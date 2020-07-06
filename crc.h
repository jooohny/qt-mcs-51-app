#ifndef CRC_H
#define CRC_H

#include <QObject>

uint16_t calcCRC16(QByteArray &buff, int length);

#endif // CRC_H
