#include "datahandler.h"

DataHandler::DataHandler(SerialPort &port) :
    port(port),
    errorString(QString()),
    ProgMdata(QByteArray()),
    DataMdata(QByteArray()),
    isPMupToDate(false),
    isDMupToDate(false)
{

}

QByteArray &DataHandler::readProgM()
{
    QByteArray reqPM(1, request.readProgM);
    if(!isPMupToDate) {
        ProgMdata = sendRequest(reqPM, response.readProgM, isPMupToDate);
    }
    return ProgMdata;
}

bool DataHandler::eraseProgM()
{
    QByteArray erPMreq(1, request.eraseProgM);
    bool isOK = false;
    sendRequest(erPMreq, response.eraseProgM, isOK);
    return isOK;
}

QByteArray &DataHandler::readDataM()
{
    QByteArray reqDM(1, request.readDataM);
    if(!isDMupToDate) {
        DataMdata = sendRequest(reqDM, response.readDataM, isDMupToDate);
    }
    return DataMdata;
}

bool DataHandler::eraseDataM()
{
    QByteArray erDMreq(1, request.eraseDataM);
    bool isOK = false;
    sendRequest(erDMreq, response.eraseDataM, isOK);
    return isOK;
}

bool DataHandler::stopProgram()
{
    QByteArray stopProg(1, request.stopProgram);
    bool isOK = false;
    sendRequest(stopProg, response.stopProgram, isOK);
    return isOK;
}

bool DataHandler::writeProgM(QByteArray &firmware)
{
    QByteArray f(firmware);

    f.prepend(request.writeProgM);

    bool isOK = false;

    sendRequest(f, response.writeProgM, isOK);

    isPMupToDate = !isOK;

    return isOK;
}

bool DataHandler::writeDataM(QByteArray &data)
{
    QByteArray d(data);

    d.prepend(request.writeDataM);

    bool isOK = false;

    sendRequest(d, response.writeDataM, isOK);

    isDMupToDate = !isOK;

    return isOK;
}

QString DataHandler::getErrorString()
{
    return errorString;
}


QByteArray DataHandler::sendRequest(QByteArray &data, char responseID, bool &isOk)
{
    QByteArray d(data);

    uint16_t CRC16 = calcCRC16(d, d.size());

    d.append(char(CRC16)).append(char(CRC16 >> 8));

    int tries = 3;

    errorString = "Error getting responce from MCU!";

    while (tries) {
        port.writeData(d);

        if(port.waitForBytesWritten(100 + d.length() * 10000 / port.getCurrentBaudrate()) != true) {
            errorString = "Error sending request to MCU!";
            break;
        }

        if (port.waitForReadyRead(500)) {
                QByteArray buffer = port.readAll();
                while (port.waitForReadyRead(100))
                    buffer.append(port.readAll());

               // Заплатка
            //           buffer.prepend(responseID);
            //           uint16_t CRC16 = calcCRC16(buffer, buffer.size());
            //           buffer.append(char(CRC16)).append(char(CRC16 >> 8));
               //

            if ( calcCRC16(buffer, buffer.size()) == 0 &&
                buffer.at(0) == responseID)
            {
               errorString.clear();
               isOk = true;
               return buffer;
            }
        }
        tries--;
    }
    return QByteArray();
}
