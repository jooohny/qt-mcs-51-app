#include "serialport.h"

SerialPort::SerialPort() :
    port(new QSerialPort),
    currentBaudrate(QSerialPort::Baud115200)
{


}

void SerialPort::closeSerialPort()
{
    if (isConnected())
        port->close();
}

int SerialPort::getCurrentBaudrate()
{
    return currentBaudrate;
}

void SerialPort::writeData(const QByteArray &data)
{
    port->write(data);
}

bool SerialPort::waitForReadyRead(int msecs)
{
    return port->waitForReadyRead(msecs);
}

bool SerialPort::waitForBytesWritten(int msecs)
{
    return port->waitForBytesWritten(msecs);
}

QByteArray SerialPort::readAll()
{
    return port->readAll();
}

int SerialPort::openSerialPort(QString name, int baudrate)
{
    port->setPortName(name);
    port->setBaudRate(baudrate);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);

    if(port->open(QIODevice::ReadWrite) != true)
        return 1;

    currentBaudrate = baudrate;
    return 0;
}

bool SerialPort::isConnected()
{
    return port->isOpen();
}

QStringList SerialPort::checkPorts()
{
    const auto infos = QSerialPortInfo::availablePorts();
    QStringList list;
    for (const QSerialPortInfo &info : infos)
    {
        list << info.portName();
    }
    return list;
}
