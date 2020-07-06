#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>


class FileHandler
{
public:
    FileHandler(QWidget* = nullptr);
    ~FileHandler();
    int openFile();
    int openFile(QString path, bool isText = false);
    QByteArray &getFileContent();
    QString getFilePath();
    QString getLastError();
    void closeFile();
    int saveFile(QByteArray &newFileContent, QByteArray codec = "UTF-8");
    int saveNewFile(QByteArray &newFileContent);

private:
    QWidget *parent;
    QString filePath;
    QByteArray fileContent;
    QString lastError;
};

#endif // FILEHANDLER_H
