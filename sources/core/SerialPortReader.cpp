#include "SerialPortReader.h"

#include <QMap>
#include <QQmlEngine>

namespace {
    // data format: <"name">=<value>, <"name">=<value>,...
    QMap<QString, float> ParseStringToMap(QString strin) {
        QMap<QString, float> output;

        QStringList tokens = strin.split(",", Qt::SkipEmptyParts);
        for (const auto& token : tokens) {
            QStringList sub = token.split("=", Qt::SkipEmptyParts);
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

    if (datamap.contains("gx") && datamap.contains("gy") && datamap.contains("gz")) {
        // data format: gx=100.0, gy=100.0, gz=100.0
        emit newGyroscopeData(datamap.value("gx"), datamap.value("gy"), datamap.value("gz"));
    }
    if (datamap.contains("ax") && datamap.contains("ay") && datamap.contains("az")) {
        // data format: ax=100.0, ay=100.0, az=100.0
        emit newAccelerometerData(datamap.value("ax"), datamap.value("ay"), datamap.value("az"));
    }
    if (datamap.contains("mx") && datamap.contains("my") && datamap.contains("mz")) {
        // data format: mx=100.0, my=100.0, mz=100.0
        emit newMagnetometerData(datamap.value("mx"), datamap.value("my"), datamap.value("mz"));
    }
}
