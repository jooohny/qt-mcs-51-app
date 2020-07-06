#ifndef LISTINGWINDOW_H
#define LISTINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class ListingWindow;
}

class ListingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListingWindow(QWidget *parent = nullptr);
    ~ListingWindow();

    void call(QString &title, QString &content);

private:
     Ui::ListingWindow *ui;

};

#endif // LISTINGWINDOW_H
