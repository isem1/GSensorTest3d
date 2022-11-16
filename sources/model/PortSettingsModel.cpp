#include "PortSettingsModel.h"

#include <QQmlEngine>
#include <QSerialPortInfo>

void PortSettingsModel::registerQmlType() {
    qmlRegisterType<PortSettingsModel>("app", 1, 0, "PortSettingsModel");
}

PortSettingsModel::PortSettingsModel(QObject* parent)
    : QObject(parent) {

}

QStringList PortSettingsModel::getSerialPortList() noexcept {
    QStringList portNamesList;
    auto serialPorts = QSerialPortInfo::availablePorts();

    std::transform(serialPorts.begin(), serialPorts.end(), std::back_inserter(portNamesList),
        [](const QSerialPortInfo& portinfo) { return portinfo.portName(); });

    return portNamesList;
}
