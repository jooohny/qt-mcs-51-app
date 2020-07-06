#include "filehandler.h"

FileHandler::FileHandler(QWidget *parent) :
    parent(parent),
    filePath(QString()),
    fileContent(QByteArray()),
    lastError(QString())
{
}

FileHandler::~FileHandler()
{
}

int FileHandler::openFile() {

    QString filter = "A51-File (*.a51)";
    QString path = QFileDialog::getOpenFileName(parent, "Open a file", QDir::currentPath(), filter);

    return  openFile(path, true);
}

int FileHandler::openFile(QString path, bool isText)
{
    if(path.trimmed().isEmpty())
        return -1;

    QFile tempFile(path);

    if(tempFile.open(QFile::ReadWrite | QFile::Text)) {

        if(isText) {
            QTextStream stream(&tempFile);
            stream.setCodec("UTF-8");
            fileContent = stream.readAll().toUtf8();
        }
        else
            fileContent = tempFile.readAll();

        filePath = QFileInfo(tempFile).absoluteFilePath();
        QDir::setCurrent(filePath.section('/', 0, -2));
        tempFile.close();
        return 0;
    }
    else {
        lastError = tempFile.errorString();
        return 1;
    }

}

QByteArray &FileHandler::getFileContent()
{
    return  fileContent;
}

QString FileHandler::getFilePath()
{
    return filePath;
}

QString FileHandler::getLastError()
{
    return lastError;
}

void FileHandler::closeFile() {
    filePath.clear();
    lastError.clear();
}

int FileHandler::saveFile(QByteArray &newFileContent, QByteArray codec) {

    if (filePath.isEmpty())
        return saveNewFile(newFileContent);

    QFile tempFile(filePath);

    if(tempFile.open(QFile::WriteOnly | QFile::Text)) {
        tempFile.resize(0);
        QTextStream stream(&tempFile);
        stream.setCodec(QTextCodec::codecForName(codec));
        stream << newFileContent;
        tempFile.close();
        return 0;
    }
    else {
        lastError = tempFile.errorString();
        return 1;
    }
}

int FileHandler::saveNewFile(QByteArray &newFileContent)
{
    QString filter = "A51-File (*.a51)";
    QString tempFilePath = QFileDialog::getSaveFileName(parent, "Save File", QDir::currentPath(), filter);

    if(tempFilePath.isEmpty())
        return -1;

    QFile tempFile(tempFilePath);

    if(tempFile.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream stream(&tempFile);
        stream.setCodec("UTF-8");
        stream << newFileContent;
        filePath = tempFilePath;
        fileContent = newFileContent;
        tempFile.close();
        return 0;
    }
    else {
        lastError = tempFile.errorString();
        return 1;
    }

}
