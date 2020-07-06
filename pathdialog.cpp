#include "pathdialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

PathDialog::PathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &PathDialog::okClicked);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::clicked, this, &PathDialog::close);

}

void PathDialog::okClicked()
{
    QString path = ui->lineEdit->text();
    if(path.trimmed().isEmpty()) {
        return;
    }

    QFile *file = new QFile (path);

    if(file->open(QFile::ReadOnly | QFile::Text)) {
        emit flashFile(file);
        close();
        return;
    }
    QMessageBox::information(this, "Error", "Path is not correct!");
}



PathDialog::~PathDialog()
{
    delete ui;
}
