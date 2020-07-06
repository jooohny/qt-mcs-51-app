#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtSerialPort>

class SerialPort
{
public:
    SerialPort();

    static QStringList checkPorts();
    int openSerialPort(QString name, int baudrate);
    bool isConnected();
    void closeSerialPort();
    int getCurrentBaudrate();
    void writeData(const QByteArray &data);
    bool waitForReadyRead(int msecs = 30000);
    bool waitForBytesWritten(int msecs = 30000);
    QByteArray readAll();

private:
     QSerialPort *port;
     int currentBaudrate;
};

#endif // SERIALPORT_H
