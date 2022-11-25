#include "SerialPortReader.h"

#include <QMap>
#include <QQmlEngine>
#include <list>

namespace {
    constexpr int fSize = 10;

    template <int Size>
    class AvgFilter {
    public:
        int GetValue(float newValue) {
            m_data.push_back(newValue);
            if (m_data.size() >= Size)
                m_data.pop_front();

            return static_cast<int>(GetDataAvg());
        }

    private:
        float GetDataAvg() {
            double sum = 0.0;
            for (auto&& j : m_data)
                sum += j;

            return sum / m_data.size();
        }

        std::list<float> m_data;
    };

    AvgFilter<fSize> fyaw;
    AvgFilter<fSize> fpitch;
    AvgFilter<fSize> froll;
}

namespace {
    // data format: <"name">=<value>, <"name">=<value>,...
    QMap<QString, float> ParseStringToMap(QString strin) {
        QMap<QString, float> output;

        QStringList tokens = strin.split(",", Qt::SkipEmptyParts);
        for (const auto& token : tokens) {
            QStringList sub = token.split(":", Qt::SkipEmptyParts);
            if (sub.size() == 2) {
                output.insert(sub.first().trimmed(), sub.last().toFloat());
            }
        }
        return output;
    }
}

void SerialPortReader::registerQmlType() {
    qmlRegisterType<SerialPortReader>("app", 1, 0, "SerialPortReader");
}

SerialPortReader::SerialPortReader(QObject* parent)
    : QObject(parent) {

}

bool SerialPortReader::openSerialPort(QString name, int speed) {
    if (m_pSerialPort) {
        m_pSerialPort->close();
    }

    m_pSerialPort = new QSerialPort();

    connect(m_pSerialPort, &QSerialPort::readyRead,
            this, &SerialPortReader::readPortData);

    m_pSerialPort->setPortName(name);
    m_pSerialPort->setBaudRate(speed);

    m_pSerialPort->setDataBits(QSerialPort::Data8);
    m_pSerialPort->setParity(QSerialPort::NoParity);
    m_pSerialPort->setStopBits(QSerialPort::OneStop);
    m_pSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Opening port name: " << name << " speed: " << speed;
    return m_pSerialPort->open(QIODevice::ReadOnly);
}

void SerialPortReader::readPortData() {
    QByteArray rawData = m_pSerialPort->readLine();
    QString strdata = QString::fromLocal8Bit(rawData);
    auto datamap = ParseStringToMap(strdata);

    if (datamap.contains("rotX") && datamap.contains("rotY") && datamap.contains("rotZ")) {
        // data format: gx=100.0, gy=100.0, gz=100.0
        emit newGyroscopeData(datamap.value("rotX"), datamap.value("rotY"), datamap.value("rotZ"));

        float rx = datamap.value("rotX"), ry = datamap.value("rotY"), rz = datamap.value("rotZ");
        float roll = atan2(ry, rz) * 57.3;
        float pitch = atan2((-rx) , sqrt(ry*ry + rz*rz)) * 57.3;
        emit newAngleDataG(pitch, roll);
    }
    if (datamap.contains("gX") && datamap.contains("gY") && datamap.contains("gZ")) {
        // data format: ax=100.0, ay=100.0, az=100.0
        emit newAccelerometerData(datamap.value("gX"), datamap.value("gY"), datamap.value("gZ"));

        float gx = datamap.value("gX"), gy = datamap.value("gY"), gz = datamap.value("gZ");
        float roll = atan2(gy, gz) * 57.3;
        float pitch = atan2((-gx) , sqrt(gy*gy + gz*gz)) * 57.3;
        emit newAngleDataA(pitch, roll);
    }
    if (datamap.contains("mx") && datamap.contains("my") && datamap.contains("mz")) {
        // data format: mx=100.0, my=100.0, mz=100.0
        emit newMagnetometerData(datamap.value("mx"), datamap.value("my"), datamap.value("mz"));
    }

    if (datamap.contains("yaw"), datamap.contains("pitch"), datamap.contains("roll")) {
        emit newAngleDataC(datamap.value("pitch"), datamap.value("roll"));

        emit newAngleDataC2(
                    fyaw.GetValue(datamap.value("yaw")),
                    fpitch.GetValue(datamap.value("pitch")),
                    froll.GetValue(datamap.value("roll")));
    }
}
