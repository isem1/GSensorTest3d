#pragma once

#include <QObject>
#include <QString>
#include <QSerialPort>

class SerialPortReader : public QObject {
    Q_OBJECT

signals:
    void newGyroscopeData(float x, float y, float z);
    void newAccelerometerData(float x, float y, float z);
    void newMagnetometerData(float x, float y, float z);

public:
    static void registerQmlType();
    SerialPortReader(QObject* parent = nullptr);

    Q_INVOKABLE bool openSerialPort(QString name, int speed);

private slots:
    void readPortData();

private:
    QSerialPort* m_pSerialPort = nullptr;
};
