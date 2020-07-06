#ifndef COMPILER_H
#define COMPILER_H

#include <QProcess>
#include <QDebug>

class Compiler
{
public:
    Compiler();
    ~Compiler();
    int compile(QString);
    int link(QString);
    int createHEX(QString);
    int createBIN(QStringList hexFiles, QString binPath);
    int buildAll(QString);
    QByteArray &getLastStatus();
    QString getErrorString();

private:
    QProcess *console;
    QByteArray lastStatus;
    QString errorString;

};

#endif // COMPILER_H
