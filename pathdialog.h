#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Dialog;
}

class PathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PathDialog(QWidget *parent = nullptr);
    ~PathDialog();

private:
    Ui::Dialog *ui;
    void okClicked();

signals:
    void flashFile(QFile*);
};

#endif // DIALOG_H
