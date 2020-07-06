#include "compiler.h"

#include <QDebug>

Compiler::Compiler() :
        console(new QProcess()),
        lastStatus(QByteArray()),
        errorString(QString())
{

}

Compiler::~Compiler()
{

}



int Compiler::compile(QString filePath)
{
    console->start("Compiler/A51.exe", QStringList() << filePath);
    console->waitForReadyRead();
    lastStatus.clear();
    lastStatus = console->readAllStandardOutput();
    console->waitForFinished();
    int exitCode = console->exitCode();
    if (exitCode != 0)
        errorString = "Error while compiling!";
    return exitCode;
}

int Compiler::link(QString filePath)
{
    if (filePath.contains(" "))
        filePath.prepend("'").append("'");
    console->start("Compiler/BL51.exe", QStringList() << filePath);
    console->waitForStarted();
    console->waitForReadyRead();
    lastStatus.clear();
    lastStatus = console->readAllStandardOutput();
    console->waitForFinished();
    int exitCode = console->exitCode();
    if (exitCode != 0)
        errorString = "Error while linking!";
    return exitCode;
}

int Compiler::createHEX(QString filePath)
{
    console->start("Compiler/OH51.exe", QStringList() << filePath);
    console->waitForReadyRead();
    lastStatus.clear();
    lastStatus = console->readAllStandardOutput();
    console->waitForFinished();
    int exitCode = console->exitCode();
    if (exitCode != 0)
        errorString = "Error while creating HEX!";
    return exitCode;
}

int Compiler::createBIN(QStringList hexFiles, QString binPath)
{
    QStringList parameters;

    for (const QString &hex : hexFiles)
        parameters << hex << "-Intel";

    console->start("Compiler/srec_cat.exe", parameters  << "-o"
                                                        << binPath
                                                        << "-Binary");


    console->waitForReadyRead();
    console->waitForFinished();

    lastStatus.clear();

    int exitCode = console->exitCode();
    if (exitCode == 0)
        lastStatus = "Firmware building completed successfully!";
    else
        lastStatus = console->readAllStandardError();
    return exitCode;
}

QByteArray &Compiler::getLastStatus()
{
    return lastStatus;
}

QString Compiler::getErrorString()
{
    QString ret = errorString;
    errorString = QString();
    return ret;
}


