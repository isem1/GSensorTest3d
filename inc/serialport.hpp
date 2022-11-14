#pragma once

#include <QSerialPortInfo>
#include <QSerialPort>
#include <QString>

class SceneModifier;

class VirtualPort : public QObject {
    Q_OBJECT

public:
    VirtualPort();
    ~VirtualPort();

    void setModifier(SceneModifier* sceneModifier) noexcept;
    void openComPort(QString name, QString speed);

private slots:
    void readData();

private:
    void connectReadEvent() noexcept;
    bool isUpdateNeeded(int angleX, int angleY) noexcept;

    QSerialPort* m_hComPort;
    SceneModifier* m_pModifier;
};
