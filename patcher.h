#ifndef PATCHER_H
#define PATCHER_H

#include "filehandler.h"
#include <QTextCursor>
#include <QTextDocument>
#include "filehandler.h"

class Patcher
{

public:
    Patcher();
    ~Patcher();

    int patch(QString filePath, QString patchPath, int cursopPos, QByteArray codec);
    int patchCode(QString filePath, QString patchPath, int breakpoint, QByteArray codec);
    QString &getPatchedFilePath();
    QString &getWorkingDir();
    QString getErrorString();

private:
    QString patchedFilePath;
    QString workingDir;
    QString errorString;
};

#endif // PATCHER_H
