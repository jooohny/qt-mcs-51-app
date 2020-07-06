#include "listingwindow.h"
#include "ui_listingwindow.h"

ListingWindow::ListingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListingWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setReadOnly(true);
    this->setMinimumWidth(800);
    this->setMinimumHeight(600);

}

ListingWindow::~ListingWindow()
{
    delete ui;
}

void ListingWindow::call(QString &title, QString &content)
{
    ui->textEdit->setText(content);
    this->setWindowTitle(title);
    this->show();
}


