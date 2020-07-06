#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include <QMainWindow>

namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemoryWindow(int rowCount, QWidget *parent = nullptr, bool isEditEn = true);
    ~MemoryWindow();
    void call(char *data, QString title = QString());

private:
    Ui::MemoryWindow *ui;

    void editMemory();
signals:
    void eraseMemory();
};

#endif // MEMORYWINDOW_H
