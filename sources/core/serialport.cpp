#include <QtCore/QDebug>

#include "scenemodifier.hpp"
#include "parameters.hpp"
#include "serialport.hpp"

VirtualPort::VirtualPort() {
    m_hComPort = nullptr;
    m_pModifier = nullptr;
}

VirtualPort::~VirtualPort() {
    if (m_hComPort == nullptr)
        return;

    if (m_hComPort->isOpen())
        m_hComPort->close();
    delete m_hComPort;

    qDebug() << "-----------------------------------";
    qDebug() << "          COMPORT CLOSED           ";
    qDebug() << "-----------------------------------";
}

void VirtualPort::setModifier(SceneModifier* sceneModifier) noexcept {
    m_pModifier = sceneModifier;
}

void VirtualPort::openComPort(QString name, QString speed) {
    if (m_hComPort != nullptr)
        return;

    m_hComPort = new QSerialPort();

    connectReadEvent();

    m_hComPort->setPortName(name);
    m_hComPort->setBaudRate(speed.toInt());
    m_hComPort->setDataBits(QSerialPort::Data8);
    m_hComPort->setParity(QSerialPort::NoParity);
    m_hComPort->setStopBits(QSerialPort::OneStop);
    m_hComPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_hComPort->open(QIODevice::ReadOnly)) {
        qDebug() << "-----------------------------------";
        qDebug() << "          COMPORT OPENED           ";
        qDebug() << "-----------------------------------";
    }
    else {
        qDebug() << "Error" << m_hComPort->error()
            << " : " << m_hComPort->errorString();
    }
}

void VirtualPort::readData() {
    QByteArray axisXY = m_hComPort->readAll();

    if (axisXY.size() != ProjOpt::packageSize) {
        qDebug() << "Incompatible data format!" << " Expected: "
                 << ProjOpt::packageSize << " Provided: " << axisXY.size();
        return;
    }

    int coordX = static_cast<int>(axisXY.data()[0]);
    int coordY = static_cast<int>(axisXY.data()[1]);

    if (isUpdateNeeded(coordX, coordY)) {
        m_pModifier->setCuboidRotationX(coordX);
        m_pModifier->setCuboidRotationY(coordY);

        // continuous debug output
        qDebug() << "X: " << coordX;
        qDebug() << "Y: " << coordY;
        qDebug() << '\n';
    }
}

void VirtualPort::connectReadEvent() noexcept {
    connect(m_hComPort, &QSerialPort::readyRead, this, &VirtualPort::readData);
}

bool VirtualPort::isUpdateNeeded(int angleX, int angleY) noexcept {
    if (m_pModifier == nullptr)
        return false;

    if (abs(angleX - m_pModifier->getCuboidRotationX()) > ProjOpt::coordEps ||
        abs(angleY - m_pModifier->getCuboidRotationY()) > ProjOpt::coordEps) {
        return true;
    }

    return false;
}
