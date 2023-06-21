QT.bluetooth.VERSION = 6.4.0
QT.bluetooth.name = QtBluetooth
QT.bluetooth.module = Qt6Bluetooth
QT.bluetooth.libs = $$QT_MODULE_LIB_BASE
QT.bluetooth.ldflags = 
QT.bluetooth.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtBluetooth
QT.bluetooth.frameworks = 
QT.bluetooth.bins = $$QT_MODULE_BIN_BASE
QT.bluetooth.depends =  core network dbus
QT.bluetooth.uses = 
QT.bluetooth.module_config = v2
QT.bluetooth.DEFINES = QT_BLUETOOTH_LIB
QT.bluetooth.enabled_features = bluez
QT.bluetooth.disabled_features = 
QT_CONFIG += bluez
QT_MODULES += bluetooth

