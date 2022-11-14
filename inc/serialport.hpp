#pragma once

#include <QSerialPortInfo>
#include <QSerialPort>
#include <QString>

class SceneModifier;

class VirtualPort
    :   public QObject
{
    Q_OBJECT

public:
    VirtualPort();
    ~VirtualPort();

    void setModifier( SceneModifier* _modifier ) noexcept;
    void openComPort( QString _name, QString _speed );

private slots:
    void readData();

private:
    void connectReadEvent() noexcept;
    bool isUpdateNeeded( int _angleX, int _angleY ) noexcept;

    QSerialPort* m_hComPort;
    SceneModifier* m_pModifier;
};
