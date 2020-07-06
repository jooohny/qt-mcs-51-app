#include "memorywindow.h"
#include "ui_memorywindow.h"

MemoryWindow::MemoryWindow(int rowCount, QWidget *parent, bool isEditEn) :
    QMainWindow(parent),
    ui(new Ui::MemoryWindow)
{
    ui->setupUi(this);
    if(!isEditEn)
         ui->eraseButton->setHidden(true);

    ui->editButton->setHidden(true);

    ui->memoryTable->setColumnCount(16);
    ui->memoryTable->setRowCount(rowCount);

    QFont font = ui->memoryTable->verticalHeader()->font();
    font.setBold(true);
    ui->memoryTable->verticalHeader()->setFont(font);
    ui->memoryTable->horizontalHeader()->setFont(font);
    ui->memoryTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QStringList horHeader = QStringList();

    for (int i = 0; i < 16; ++i) {
        QString str = QByteArray::number(i, 16).toUpper().prepend("0");
        horHeader << str;
    }
    ui->memoryTable->setHorizontalHeaderLabels(horHeader);

    ui->memoryTable->resizeColumnsToContents();
    ui->memoryTable->resizeRowsToContents();
    ui->memoryTable->setFixedWidth(ui->memoryTable->horizontalHeader()->length()
                                   + ui->memoryTable->verticalHeader()->width()
                                   + 16);


    this->setMaximumWidth(this->width());
    this->setMinimumHeight(this->height());

    connect(ui->editButton, &QPushButton::pressed, this,  &MemoryWindow::editMemory);
    connect(ui->closeButton, &QPushButton::pressed, this, &MemoryWindow::close);
}

MemoryWindow::~MemoryWindow()
{
    delete ui;
}

void MemoryWindow::call(char *pointer, QString title)
{
    ui->memoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->memoryTable->setFocusPolicy(Qt::NoFocus);
    ui->memoryTable->setShowGrid(false);
    ui->memoryTable->horizontalHeader()->hide();
    ui->statusbar->clearMessage();
    this->setWindowTitle(title);

    QByteArray data(pointer, ui->memoryTable->rowCount() * 16);

    QString str = data.toHex('\n').toUpper();
    QStringList strL = str.split('\n');

    for (int i = 0; i < ui->memoryTable->rowCount(); i++) {
        for (int j = 0; j < ui->memoryTable->columnCount(); j++) {
            QTableWidgetItem *itm =  new QTableWidgetItem (strL[ i*16 + j ]);
            QString addr = QByteArray::number(i, 16).toUpper();
            if(addr.length() < 2)
                addr.prepend("0");
            QTableWidgetItem *header = new QTableWidgetItem(addr);
            ui->memoryTable->setVerticalHeaderItem(i, header);
            itm->setTextAlignment(Qt::AlignCenter);
            ui->memoryTable->setItem(i, j, itm);
        }
    }

    this->show();
}

void MemoryWindow::editMemory()
{
    ui->editButton->setEnabled(false);
    ui->memoryTable->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->memoryTable->setFocusPolicy(Qt::StrongFocus);
    ui->memoryTable->setShowGrid(true);
    ui->memoryTable->horizontalHeader()->show();
    ui->statusbar->showMessage("Edit table and then press OK");
}
