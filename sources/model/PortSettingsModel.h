#pragma once

#include <QObject>
#include <QString>

class PortSettingsModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QStringList serialPortList READ getSerialPortList CONSTANT)

public:
    static void registerQmlType();

    PortSettingsModel(QObject* parent = nullptr);

private:
    QStringList getSerialPortList() noexcept;
};
