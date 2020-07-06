#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtSerialPort>
#include <QCloseEvent>
#include <QComboBox>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QFileDialog>
#include <QTextCodec>
#include <QLabel>
#include <QPushButton>

#include "listingwindow.h"
#include "memorywindow.h"
#include "regtable.h"
#include "serialport.h"
#include "filehandler.h"
#include "compiler.h"
#include "patcher.h"
#include "datahandler.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FrontWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrontWindow(QString title = QString(), QWidget *parent = nullptr);
    ~FrontWindow();


private slots:
    void open();
    int build();
    void upload();
    void stopProgram();
    void connectWithINI();
    void updatePorts();
    void reconnect(QString);
    void newFile();
    int save();
    void toggleBreakpoint();
    int saveAs();
    void watchLST();
    void about();
    void showExtPM();
    void showExtDM();
    void showRAM();
    void showRegisters();
    void showFirmware();
public slots:
    void eraseProgM();
    void eraseDataM();


private:
    QString title;
    Ui::MainWindow *ui;
    QComboBox *portsComboBox;
    QComboBox *codecComboBox;

    QLabel *space;

    SerialPort COM;
    FileHandler currentFile;
    DataHandler dataHandler;
    Compiler compiler;
    ListingWindow lw;
    MemoryWindow *DMwindow;
    MemoryWindow *PMwindow;
    MemoryWindow *RAMwindow;
    MemoryWindow *firmwareWindow;
    RegTable rt;
    Patcher patcher;
    int breakpointPos;
    bool isFileEdited;
    QString firmwarePath;
    QString appPath;
    QString getAppDataPath();

    void closeEvent (QCloseEvent*);
    void fileEdited();
    void watchChanges();
    void reInit();
    void openFileInit();
    int onCloseMessageBox();
    int beforeCloseFile();
    int createFirmware();

    void statusMessage(const QString &message);
};
#endif // MAINWINDOW_H
