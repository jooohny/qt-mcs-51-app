#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "serialport.h"
#include "crc.h"

struct messageIDs
{
    char writeProgM;
    char readProgM;
    char eraseProgM;
    char writeDataM;
    char readDataM;
    char eraseDataM;
    char stopProgram;
};

class DataHandler
{
public:
    DataHandler(SerialPort &port);

    bool writeProgM(QByteArray &firmware);
    QByteArray &readProgM();
    bool eraseProgM();

    bool writeDataM(QByteArray &data);
    QByteArray &readDataM();
    bool eraseDataM();

    bool stopProgram();

    QString getErrorString();

private:
    messageIDs request{0x11, 0x13, 0x15, 0x17, 0x19, 0x21, 0x23};
    messageIDs response{0x12, 0x14, 0x16, 0x18, 0x20, 0x22, 0x24};

    SerialPort &port;

    QString errorString;

    QByteArray sendRequest(QByteArray &data, char responseID, bool &isOk);

    QByteArray ProgMdata;
    QByteArray DataMdata;

    bool isPMupToDate;
    bool isDMupToDate;
};

#endif // DATAHANDLER_H
