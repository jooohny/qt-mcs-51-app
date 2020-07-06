#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QScrollBar>


namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemoryWindow(int rowCount, QWidget *parent = nullptr, bool isEditEn = true);
    ~MemoryWindow();
    void fillUp(char *data, QString title = QString(), QByteArray textCodec = "Windows-1251");
    void contentErased();

private:
    Ui::MemoryWindow *ui;
    void eraseMemory();
    QFont itmFont;
    void addHeaderContent();
    void fillContent(char *pointer, QByteArray textCodec = "Windows-1251");

signals:
    void erase();

};

#endif // MEMORYWINDOW_H
