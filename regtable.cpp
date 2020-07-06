#include "regtable.h"
#include "ui_regtable.h"

RegTable::RegTable(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::RegTable),
    addrSFR1(QByteArray()),
    addrSFR2(QByteArray()),
    addrSFR3(QByteArray()),
    addrBank(QByteArray())
{
    ui->setupUi(this);
    this->setWindowTitle("MCS-51 Registers Table");

    addrBank.append(char(0x00))
            .append(0x01)
            .append(0x02)
            .append(0x03)
            .append(0x04)
            .append(0x05)
            .append(0x06)
            .append(0x07);

    addrSFR1
            .append(0xE0)
            .append(0xF0)
            .append(0xD0)
            .append(0x80)
            .append(0x90)
            .append(0xA0)
            .append(0xB0);

    addrSFR2
            .append(0x81)
            .append(0x83)
            .append(0x82)
            .append(0x8C)
            .append(0x8A)
            .append(0x8D)
            .append(0x8B);

    addrSFR3
            .append(0x89)
            .append(0x88)
            .append(0xB8)
            .append(0xA8)
            .append(0x87)
            .append(0x98)
            .append(0x99);

    initTable(ui->dataBankTable, 1, 8, QStringList() << "R0" << "R1" << "R2" << "R3" << "R4" << "R5" << "R6" << "R7");
    initTable(ui->dataSFRtable, 1, 7, QStringList() << "ACC" << "B" << "PSW" << "P0" << "P1" << "P2" << "P3");
    initTable(ui->dataSFRtable_2, 1, 7, QStringList() << "SP" << "DPH" << "DPL" << "TH0" << "TL1" << "TH1" << "TL1");
    initTable(ui->dataSFRtable_3, 1, 7, QStringList() << "TMOD" << "TCON" << "IP" << "IE" << "PCON" << "SCON" << "SBUF");


    for (int i = 0; i < ui->dataBankTable->columnCount(); i++) {
        QTableWidgetItem *itm =  new QTableWidgetItem (tr("%1").arg("FF"));
        itm->setTextAlignment(Qt::AlignCenter);
        ui->dataBankTable->setItem(0, i, itm);
    }

    ui->dataBankTable->setFixedSize(ui->dataBankTable->horizontalHeader()->length() +
                                    ui->dataBankTable->verticalHeader()->width(),
                                    ui->dataBankTable->verticalHeader()->length() +
                                    ui->dataBankTable->horizontalHeader()->height());

}

RegTable::~RegTable()
{
    delete ui;
}

void RegTable::initTable(QTableWidget *table, int rowCount, int columnCount, QStringList header)
{
    table->setRowCount(rowCount);
    table->setColumnCount(columnCount);
    table->setHorizontalHeaderLabels(header);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->hide();
    QFont font = table->horizontalHeader()->font();
    font.setBold(true);
    table->horizontalHeader()->setFont(font);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setFocusPolicy(Qt::NoFocus);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}


void RegTable::fillSFRtable(QTableWidget *table, QByteArray &RAMdata, QByteArray &addr, int offset)
{
    for (int i = 0; i < table->columnCount(); i++) {
        char chAddr = addr[i];
        int intAddr = (int) reinterpret_cast<unsigned char&>(chAddr) + offset * 8;
        char chByte = RAMdata[intAddr];
        int intByte = (int) reinterpret_cast<unsigned char&>(chByte);
        QString byteStr = QByteArray::number(intByte, 16);
        if(byteStr.length() < 2)
            byteStr.prepend("0");

        QTableWidgetItem *itm =  new QTableWidgetItem(byteStr);
        itm->setTextAlignment(Qt::AlignCenter);
        table->setItem(0, i, itm);
    }

    table->resizeColumnsToContents();
    table->setFixedSize(ui->dataBankTable->horizontalHeader()->length() +
                                     ui->dataBankTable->verticalHeader()->width(),
                                     ui->dataBankTable->verticalHeader()->length() +
                                     ui->dataBankTable->horizontalHeader()->height());

}


void RegTable::call(char *PMpointer)
{
    QByteArray RAM(PMpointer, 256);

    char bankFlag = (addrSFR1[3] & 0b11000) >> 3;
    int bankOffset = (int) reinterpret_cast<unsigned char&>(bankFlag);

    fillSFRtable(ui->dataBankTable, RAM, addrBank, bankOffset);
    fillSFRtable(ui->dataSFRtable, RAM, addrSFR1);
    fillSFRtable(ui->dataSFRtable_2, RAM, addrSFR2);
    fillSFRtable(ui->dataSFRtable_3, RAM, addrSFR3);

    this->adjustSize();
    this->setFixedSize(this->size());
    this->show();
}
