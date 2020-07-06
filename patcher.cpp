#include "patcher.h"

int Patcher::patch(QString filePath, QString patchPath, int cursopPos, QByteArray codec)
{
    FileHandler file;
    FileHandler patch;

    if( patch.openFile(patchPath, true) != 0)
    {
        errorString = "Unable to open patching file.";
        return  1;
    }

    if(file.openFile(filePath) != 0)
    {
        errorString = "Unable to open patched file.";
        return  1;
    }

    QTextDocument doc(file.getFileContent());
    QTextCursor cursor(&doc);

    if (cursopPos != -1)
        cursor.setPosition(cursopPos);
    else
    {
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);

        while(cursor.selectedText().trimmed().isEmpty()) {
            if (cursor.atStart()) {
                errorString = "Inner process problems with cursor.";
                return 1;
            }
            cursor.removeSelectedText();
            cursor.movePosition(QTextCursor::Up);
            cursor.select(QTextCursor::LineUnderCursor);
        }
        cursor.movePosition(QTextCursor::StartOfLine);

    }

    cursor.insertText(patch.getFileContent() + "\n");
    QByteArray newContent = doc.toPlainText().toUtf8();
    if(file.saveFile(newContent, codec) != 0) {
        errorString = "Error while saving patched file.";
        return 1;
    }
    file.closeFile();
    patch.closeFile();
    patchedFilePath = filePath;
    return 0;
}

int Patcher::patchCode(QString filePath, QString patchPath, int breakpoint, QByteArray codec) {

    QString dirpath = filePath.section('/', 0, -2);

    QDir temp(dirpath);

    QString dirName = filePath.section('/', -1, -1).section('.', -2, 0);
    QString fileCopy = temp.absolutePath() + '/' + dirName + '/' + filePath.section('/', -1, -1);

    if(!(temp.exists(dirName)))
        temp.mkdir(dirName);

    if(!(temp.cd(dirName))) {
        errorString = "Unable to access " + dirName;
        return 1;
    }

    if(temp.exists(fileCopy))
        temp.remove(fileCopy);


    if (!(QFile::copy(filePath, fileCopy))) {
        errorString = "Unable to create file copy " + fileCopy;
        return 1;
    }
    workingDir = temp.absolutePath();
    return patch(fileCopy, patchPath, breakpoint, codec);
}

QString &Patcher::getPatchedFilePath()
{
    return patchedFilePath;
}

QString &Patcher::getWorkingDir()
{
    return workingDir;
}

QString Patcher::getErrorString()
{
    QString ret = errorString;
    errorString = QString();
    return ret;
}


Patcher::Patcher() :
    errorString(QString())
{

}

Patcher::~Patcher()
{

}
