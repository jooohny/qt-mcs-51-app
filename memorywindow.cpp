#include "memorywindow.h"
#include "ui_memorywindow.h"

QString bytesToString(const QByteArray &data);

MemoryWindow::MemoryWindow(int rowCount, QWidget *parent, bool isEditEn) :
    QMainWindow(parent),
    ui(new Ui::MemoryWindow),
    itmFont("Consolas", 10)
{
    ui->setupUi(this);
    if(!isEditEn)
         ui->eraseButton->setHidden(true);

    ui->editButton->setHidden(true);

    ui->memoryTable->setColumnCount(2);
    ui->memoryTable->setRowCount(rowCount);
    addHeaderContent();

    QFont headerFont(itmFont);
    headerFont.setBold(true);

    QHeaderView *vertHeader = ui->memoryTable->verticalHeader();

    vertHeader->setFont(headerFont);
    vertHeader->setFixedWidth(vertHeader->width());
    vertHeader->setSectionResizeMode(QHeaderView::Fixed);
    ui->memoryTable->horizontalHeader()->hide();
    ui->memoryTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->memoryTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    this->setMinimumHeight(this->height());

    ui->memoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->memoryTable->setFocusPolicy(Qt::NoFocus);
    ui->memoryTable->setShowGrid(false);

    connect(ui->eraseButton, &QPushButton::pressed, this,  &MemoryWindow::eraseMemory);
    connect(ui->closeButton, &QPushButton::pressed, this, &MemoryWindow::close);
}

MemoryWindow::~MemoryWindow()
{
    delete ui;
}

void MemoryWindow::fillUp(char *data, QString title, QByteArray textCodec)
{
    this->setWindowTitle(title);
    ui->statusbar->clearMessage();

    fillContent(data, textCodec);

    ui->memoryTable->resizeColumnsToContents();
    ui->memoryTable->resizeRowsToContents();

    ui->memoryTable->viewport()->setFixedWidth(ui->memoryTable->horizontalHeader()->length()
                                   + ui->memoryTable->verticalHeader()->width());

    ui->memoryTable->setFixedWidth(ui->memoryTable->horizontalHeader()->length()
                                   + ui->memoryTable->verticalHeader()->width() + 19);

    this->adjustSize();
    this->setFixedSize(this->size());
}

void MemoryWindow::eraseMemory()
{
    contentErased();
//    emit erase();
}

void MemoryWindow::addHeaderContent()
{
    int rowCount = ui->memoryTable->rowCount() - 1;
    int digitsNum = QByteArray::number(rowCount * 0x10, 16).length();

    for (int i = 0; i <= rowCount; i++) {
        QString addr = QByteArray::number(i * 0x10, 16).toUpper();
        while (addr.length() < digitsNum)
            addr.prepend("0");
        QTableWidgetItem *header = new QTableWidgetItem(addr);
        header->setFont(itmFont);

        ui->memoryTable->setVerticalHeaderItem(i, header);
    }
}

void MemoryWindow::fillContent(char *pointer, QByteArray textCodec)
{

    for (int i = 0; i < ui->memoryTable->rowCount(); i++) {
        QByteArray data(pointer, 16);

        QString str = bytesToString(data);
        QTableWidgetItem *itm =  new QTableWidgetItem (str);
        itm->setTextAlignment(Qt::AlignCenter);
        itm->setFont(itmFont);
        ui->memoryTable->setItem(i, 0, itm);

        QTextCodec *codec = QTextCodec::codecForName(textCodec);
        QString string = codec->toUnicode(data).prepend("  ");
        QTableWidgetItem *strItem =  new QTableWidgetItem (string);
        strItem->setTextAlignment(Qt::AlignLeft);
        strItem->setFont(itmFont);
        ui->memoryTable->setItem(i, 1, strItem);

        pointer += 16;
    }

}

void MemoryWindow::contentErased()
{
    QByteArray empty(ui->memoryTable->rowCount() * 16, char(0x00));
    fillContent(empty.data());
}



QString bytesToString(const QByteArray &data)
{
    static const char numbers[] = "0123456789ABCDEF";
    QString r;
    r.resize(data.size()*3-1);
    int rpos = 0;
    for (int i = 0; i < data.size(); ++i) {
        uchar c = data.at(i);
        r[rpos++] = QChar(numbers[(c >> 4) % 16]);
        r[rpos++] = QChar(numbers[c % 16]);
        if (i != data.size() - 1)
            r[rpos++] = QChar(' ');
    }
    return r;
}


