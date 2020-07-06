#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>


FrontWindow::FrontWindow(QString title, QWidget *parent) : QMainWindow(parent),
    title(title),
    ui(new Ui::MainWindow),
    portsComboBox(new QComboBox),
    codecComboBox(new QComboBox),
    space(new QLabel(" ", this)),
    COM(SerialPort()),
    currentFile(FileHandler(this)),
    dataHandler(DataHandler(COM)),
    compiler(Compiler()),
    lw(new ListingWindow(this)),
    DMwindow(new MemoryWindow(128, this)),
    PMwindow(new MemoryWindow(128, this)),
    RAMwindow(new MemoryWindow(8, this, false)),
    firmwareWindow(new MemoryWindow(128, this, false)),
    rt(new RegTable(this)),
    patcher(Patcher()),
    breakpointPos(-1),
    firmwarePath(QString()),
    appPath(qApp->applicationDirPath())
{
    ui->setupUi(this);
    updatePorts();
    reInit();
    connectWithINI();

    QAction *actionAbout = ui->menuBar->addAction("About");

    ui->toolBar->addAction(ui->actionOpen);
    ui->toolBar->addAction(ui->actionSave);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionBuild);
    ui->toolBar->addAction(ui->actionRun);
    ui->toolBar->addAction(ui->actionShowRegisters);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(portsComboBox);
    ui->toolBar->addWidget(space);
    ui->toolBar->addWidget(codecComboBox);
    codecComboBox->addItems(QStringList() << "Windows-1251" << "IBM 866");





    connect(portsComboBox, &QComboBox::currentTextChanged, this, &FrontWindow::reconnect);
//    connect(portsComboBox, &QComboBox::textActivated, this, &FrontWindow::reconnect);
    connect(ui->actionNew, &QAction::triggered, this, &FrontWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered, this, &FrontWindow::open);
    connect(ui->actionSave, &QAction::triggered, this, &FrontWindow::save);
    connect(ui->actionSaveAs, &QAction::triggered, this, &FrontWindow::saveAs);

    connect(ui->actionBuild, &QAction::triggered, this, &FrontWindow::build);
    connect(ui->actionRun, &QAction::triggered, this, &FrontWindow::upload);
    connect(ui->actionToggleBreakpoint, &QAction::triggered, this, &FrontWindow::toggleBreakpoint);
    connect(ui->actionStopProgram, &QAction::triggered, this, &FrontWindow::stopProgram);

    connect(ui->actionShowLST, &QAction::triggered, this, &FrontWindow::watchLST);
    connect(ui->actionShowPM, &QAction::triggered, this, &FrontWindow::showExtPM);
    connect(ui->actionShowDM, &QAction::triggered, this, &FrontWindow::showExtDM);
    connect(ui->actionShowRegisters, &QAction::triggered, this, &FrontWindow::showRegisters);
    connect(ui->actionShowRAM, &QAction::triggered, this, &FrontWindow::showRAM);
    connect(DMwindow, &MemoryWindow::erase, this, &FrontWindow::eraseDataM);
    connect(PMwindow, &MemoryWindow::erase, this, &FrontWindow::eraseProgM);
    connect(ui->actionFirmwareWatch, &QAction::triggered, this, &FrontWindow::showFirmware);

    connect(actionAbout, &QAction::triggered, this, &FrontWindow::about);

     QFont font("Consolas", 10);

     const int tabStop = 8;  // 4 characters

     QFontMetrics metrics(font);

     ui->textEdit->setTabStopWidth(tabStop * metrics.width(' '));
     ui->textEdit->setFont(font);

}


int FrontWindow::build()
{
    ui->actionFirmwareWatch->setEnabled(false);

    if(save() != 0)
        return -1;
    int isSuccessCompiling = compiler.compile(currentFile.getFilePath());
    ui->actionShowLST->setEnabled(true);
    statusMessage(compiler.getLastStatus());
    if (isSuccessCompiling != 0) {
         watchLST();
         return 1;
    }

    return createFirmware();
}

void FrontWindow::upload()
{
    statusMessage("The firmware is being loaded.");

    if(build() != 0)
        return;

    if(COM.isConnected() == false) {
        statusMessage("Pick a COM-port to connect!");
        return;
    }

    FileHandler firmware;
    if(firmware.openFile(firmwarePath) != 0) {
        QMessageBox::warning(this, "Error", "Error opening firmware file " + firmwarePath);
        return;
    }

    if(dataHandler.writeProgM(firmware.getFileContent())) {
        statusMessage(tr("The firmware's successfully loaded."));
        return;
    }

    QMessageBox::warning(this, "Error", "Uploading failed: " + dataHandler.getErrorString());
}

void FrontWindow::stopProgram()
{
    if(dataHandler.stopProgram() == false) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }

    statusMessage("The program execution has been stopped.");
}

void FrontWindow::open()
{
    if(beforeCloseFile() == -1)
        return;
    if(currentFile.getFilePath().trimmed().isEmpty() == false)
        QDir::setCurrent(currentFile.getFilePath().section('/', 0, -2));
    int ret = currentFile.openFile();
    if(ret == -1)
        return;
    if (ret == 0)
        openFileInit();
    else
        QMessageBox::warning(this, "Error", "Error while opening file!" + currentFile.getLastError());
}


void FrontWindow::connectWithINI()
{
    QString appDataPath = getAppDataPath();
    if(appDataPath.isEmpty()){
        return;
    }


    FileHandler comINI;

    comINI.openFile(appDataPath + tr("/com.ini"), true);

    QStringList ini = QString(comINI.getFileContent()).split("\n");

    if(ini.count() < 2) {
        statusMessage("Pick a COM-port to connect!");
        return;
    }

    QString portName = ini[0];
    QString baudrate = ini[1];

    if(COM.openSerialPort(portName, baudrate.toInt()) == 0)
    {
        statusMessage(tr("Connected to %1: %2, 8, 1, None, None").arg(portName).arg(baudrate));
        portsComboBox->setCurrentText(portName);
        return;
    }
    statusMessage(tr("Error opening port! Pick a new one to connect."));
}

void FrontWindow::updatePorts()
{

    portsComboBox->clear();
    const QStringList list = COM.checkPorts();
    portsComboBox->addItems(list);
}

void FrontWindow::reconnect(QString portName)
{
    COM.closeSerialPort();
    int baudrate = COM.getCurrentBaudrate();
    if (COM.openSerialPort(portName, baudrate) == 0)
    {
        statusMessage(tr("Connected to %1: %2, 8, 1, None, None").arg(portName).arg(baudrate));
        portsComboBox->setCurrentText(portName);
        QString appDataPath = getAppDataPath();
        if(appDataPath.isEmpty())
            return;
        FileHandler comINI;
        comINI.openFile(appDataPath + tr("/com.ini"), true);
        QStringList ini = QStringList() << portName << QString::number(baudrate);
        QByteArray newContent = ini.join("\n").toUtf8();
        comINI.saveFile(newContent);
        return;
    }
    statusMessage(tr("Error opening port!"));
}

void FrontWindow::newFile()
{
    if(beforeCloseFile() == -1)
        return;
    reInit();
}

int FrontWindow::save() {

    if(currentFile.getFilePath().isEmpty())
        return saveAs();

    QByteArray newContent = ui->textEdit->toPlainText().toUtf8();
    int isSuccessSaving = currentFile.saveFile(newContent);
    if (isSuccessSaving == 0)
        watchChanges();
    else
        QMessageBox::warning(this, "Error", "Error while saving file: " + currentFile.getLastError());

    return  isSuccessSaving;
}

void FrontWindow::fileEdited() {
    isFileEdited = true;
    disconnect(ui->textEdit, nullptr);
}

void FrontWindow::watchChanges()
{
    isFileEdited = false;
    connect(ui->textEdit, &QPlainTextEdit::textChanged, this, &FrontWindow::fileEdited);

}

void FrontWindow::reInit()
{
    ui->actionShowLST->setEnabled(false);
    ui->actionStopProgram->setEnabled(false);
    ui->actionFirmwareWatch->setEnabled(false);

    ui->textEdit->clear();

    if(currentFile.getFilePath().isEmpty() == false)
            currentFile.closeFile();

    this->setWindowTitle(title);
    watchChanges();
}

void FrontWindow::openFileInit()
{
    this->setWindowTitle(currentFile.getFilePath() + " - " + title);
    ui->textEdit->setPlainText(currentFile.getFileContent());
    watchChanges();
}

int FrontWindow::onCloseMessageBox()
{
    return QMessageBox::warning(this, tr("File Sender"), // исправить имя
                                           tr("Do you want to save your changes?"),
                                           QMessageBox::Save | QMessageBox::Discard
                                           | QMessageBox::Cancel,
                                           QMessageBox::Save);
}

void FrontWindow::closeEvent (QCloseEvent *event)
{
    if (beforeCloseFile() == -1) {
        event->ignore();
        return;
    }
    event->accept();
}

void FrontWindow::toggleBreakpoint()
{
    QTextCharFormat highlighted;
    QTextCharFormat plain;
    highlighted.setBackground(Qt::yellow);
    plain.setBackground(Qt::white);

    QTextCursor cursor = ui->textEdit->textCursor();

    cursor.select(QTextCursor::LineUnderCursor);

    while(cursor.selectedText().trimmed().isEmpty()) {
        if (cursor.atEnd()) {
            breakpointPos = -1;
            return;
        }
        cursor.movePosition(QTextCursor::Down);
        cursor.select(QTextCursor::LineUnderCursor);
    }

    cursor.movePosition(QTextCursor::StartOfLine);
    int currPos = cursor.position();
    cursor.select(QTextCursor::Document);
    cursor.setCharFormat(plain);

    if(currPos == breakpointPos) {
        breakpointPos = -1;
        return;
    }

    cursor.setPosition(currPos);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.setCharFormat(highlighted);
    breakpointPos = currPos;
}

int FrontWindow::saveAs()
{
    QByteArray newContent = ui->textEdit->toPlainText().toUtf8();
    int isSuccessSaving = currentFile.saveNewFile(newContent);
    if (isSuccessSaving == 0)
        openFileInit();
    if(isSuccessSaving == 1)
        QMessageBox::warning(this, "Error", "Error while saving file: " + currentFile.getLastError());
    return isSuccessSaving;
}

void FrontWindow::watchLST()
{
    FileHandler listingFile;
    QString title;
    QString content;
    QString path = currentFile.getFilePath().section(".", -2, 0) + ".LST";

    if (listingFile.openFile(path) == 0) {
        content = listingFile.getFileContent();
        title = path;
    }
    else {
        content = "Error opening .LST file " + path + "!";
        title = "Error";
    }
    lw.call(title, content);
}

void FrontWindow::about()
{
    QMessageBox::about(this, tr("About MCS-51 IDE"),
                 tr("NovSU, 2020"));
}

void FrontWindow::showExtPM()
{
    QByteArray PM = dataHandler.readProgM();

    if(PM.isNull()) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }

    PMwindow->fillUp(PM.data() + 1, tr("External Program Memory"), codecComboBox->currentText().toUtf8());
    PMwindow->show();
}

void FrontWindow::showExtDM()
{
    QByteArray DM = dataHandler.readDataM();

    if(DM.isNull()) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }

    DMwindow->fillUp(DM.data() + 1, tr("External Data Memory"), codecComboBox->currentText().toUtf8());
    DMwindow->show();
}

void FrontWindow::showRAM()
{
    QByteArray PM = dataHandler.readProgM();

    if(PM.isNull()) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }

    RAMwindow->fillUp(PM.data() + 1 + 0x600, tr("Internal RAM"), codecComboBox->currentText().toUtf8());
    RAMwindow->show();
}

void FrontWindow::showRegisters()
{
    QByteArray PM = dataHandler.readProgM();

    if(PM.isNull()) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }
    ui->actionStopProgram->setEnabled(false);
    rt.call(PM.data() + 1 + 0x600);
}

void FrontWindow::showFirmware()
{
    firmwareWindow->show();
}

void FrontWindow::eraseProgM()
{
    if(dataHandler.eraseProgM() == false) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }
    PMwindow->contentErased();
    statusMessage("Program Memory has been erased.");
}

void FrontWindow::eraseDataM()
{
    if(dataHandler.eraseDataM() == false) {
        QMessageBox::warning(this, "Error", dataHandler.getErrorString());
        return;
    }
    DMwindow->contentErased();
    statusMessage("Program Memory has been erased.");

}

QString FrontWindow::getAppDataPath()
{
    QDir appData = QDir::temp();

    if(!appData.cdUp()) {
        QMessageBox::warning(this, "Error", "Error while accessing " + appData.absolutePath());
        return QString();
    }


    if(appData.exists("MCS-51-IDE") == false)
        appData.mkdir("MCS-51-IDE");

    if(appData.cd("MCS-51-IDE") == false) {
        QMessageBox::warning(this, "Error", "Error while creating folder in" + appData.absolutePath());
        return QString();
    }

    return appData.absolutePath();

}

int FrontWindow::beforeCloseFile()
{
    if(isFileEdited) {
        if (currentFile.getFilePath().isEmpty()
            && ui->textEdit->toPlainText().isEmpty())
            return 0;
        int resBtn = QMessageBox::warning(this, title,
                                                tr("Do you want to save your changes?"),
                                                QMessageBox::Save |
                                                QMessageBox::Discard |
                                                QMessageBox::Cancel,
                                                QMessageBox::Save);
        if (resBtn == QMessageBox::Cancel)
            return -1;
        else if (resBtn == QMessageBox::Save) {
            save(); // сохранить файл
            return 1;
        }

    }
    return 0;

}

int FrontWindow::createFirmware()
{
    if (patcher.patchCode(currentFile.getFilePath(), appPath + tr("/mon/patch.inc"), breakpointPos,  codecComboBox->currentText().toUtf8()) != 0) {
        statusMessage(patcher.getErrorString());
        QMessageBox::warning(this, "Error", "Error while patching code!");
        return 1;
    }
    QString filePath  = patcher.getPatchedFilePath().section('.', 0, -2).split("/").join("\\");
    if( compiler.compile(filePath + tr(".a51")) != 0 ||
        compiler.link(filePath + tr(".OBJ")) != 0 ||
        compiler.createHEX(filePath) != 0 ||
        compiler.createBIN(QStringList()<< filePath + tr(".hex")
                                        << appPath + tr("/mon/mon.hex"), filePath + tr(".bin") ) != 0)
    {
        QString patcherError = patcher.getErrorString();
        QString errorString = patcherError.trimmed().isEmpty() ? compiler.getLastStatus() : patcherError;
        QMessageBox::warning(this, tr("Adding monitor problems!"),  errorString);
        return 1;
    }

    ui->actionFirmwareWatch->setEnabled(true);

    firmwarePath = filePath + tr(".bin");

    FileHandler firmware;
     if (firmware.openFile(firmwarePath) == 0)
        firmwareWindow->fillUp(firmware.getFileContent().data(), tr("Firmware Watch"), codecComboBox->currentText().toUtf8());

    statusMessage(compiler.getLastStatus());
    return 0;
}


void FrontWindow::statusMessage(const QString &message) {
    ui->statusbar->showMessage(message);
}

FrontWindow::~FrontWindow()
{
    delete ui;
}
