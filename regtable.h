#ifndef REGTABLE_H
#define REGTABLE_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class RegTable;
}

class RegTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegTable(QWidget *parent = nullptr);
    ~RegTable();
    void call(char *PMpointer);

private:
    Ui::RegTable *ui;
    QByteArray addrSFR1;
    QByteArray addrSFR2;
    QByteArray addrSFR3;
    QByteArray addrBank;

    void initTable(QTableWidget *table, int rowsCount, int columnsCount, QStringList header);
    void  fillSFRtable(QTableWidget *table, QByteArray &RAMdata, QByteArray &addr, int offset = 0);

};

#endif // REGTABLE_H
