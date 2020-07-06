/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionBuild;
    QAction *actionRun;
    QAction *actionSave;
    QAction *actionToggleBreakpoint;
    QAction *actionSaveAs;
    QAction *actionShowLST;
    QAction *actionNew;
    QAction *actionShowDM;
    QAction *actionShowPM;
    QAction *actionStopProgram;
    QAction *actionShowRegisters;
    QAction *actionShowRAM;
    QAction *actionFirmwareWatch;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *textEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuProgram;
    QMenu *menuMemory;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(278, 279);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/openFile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionOpen->setIconVisibleInMenu(true);
        actionBuild = new QAction(MainWindow);
        actionBuild->setObjectName(QStringLiteral("actionBuild"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/build.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionBuild->setIcon(icon1);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/run.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/saveFile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionToggleBreakpoint = new QAction(MainWindow);
        actionToggleBreakpoint->setObjectName(QStringLiteral("actionToggleBreakpoint"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionShowLST = new QAction(MainWindow);
        actionShowLST->setObjectName(QStringLiteral("actionShowLST"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionShowDM = new QAction(MainWindow);
        actionShowDM->setObjectName(QStringLiteral("actionShowDM"));
        actionShowPM = new QAction(MainWindow);
        actionShowPM->setObjectName(QStringLiteral("actionShowPM"));
        actionStopProgram = new QAction(MainWindow);
        actionStopProgram->setObjectName(QStringLiteral("actionStopProgram"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStopProgram->setIcon(icon4);
        actionShowRegisters = new QAction(MainWindow);
        actionShowRegisters->setObjectName(QStringLiteral("actionShowRegisters"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/regTable.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowRegisters->setIcon(icon5);
        actionShowRAM = new QAction(MainWindow);
        actionShowRAM->setObjectName(QStringLiteral("actionShowRAM"));
        actionFirmwareWatch = new QAction(MainWindow);
        actionFirmwareWatch->setObjectName(QStringLiteral("actionFirmwareWatch"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 278, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuProgram = new QMenu(menuBar);
        menuProgram->setObjectName(QStringLiteral("menuProgram"));
        menuMemory = new QMenu(menuBar);
        menuMemory->setObjectName(QStringLiteral("menuMemory"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProgram->menuAction());
        menuBar->addAction(menuMemory->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuProgram->addAction(actionBuild);
        menuProgram->addAction(actionRun);
        menuProgram->addSeparator();
        menuProgram->addAction(actionToggleBreakpoint);
        menuProgram->addAction(actionStopProgram);
        menuProgram->addSeparator();
        menuProgram->addAction(actionShowLST);
        menuProgram->addAction(actionFirmwareWatch);
        menuMemory->addAction(actionShowRegisters);
        menuMemory->addAction(actionShowRAM);
        menuMemory->addSeparator();
        menuMemory->addAction(actionShowDM);
        menuMemory->addAction(actionShowPM);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open Existing File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionBuild->setText(QApplication::translate("MainWindow", "Build", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBuild->setToolTip(QApplication::translate("MainWindow", "Biuld Program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionBuild->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
        actionRun->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("MainWindow", "Upload And Run Program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRun->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionToggleBreakpoint->setText(QApplication::translate("MainWindow", "Toggle Breakpoint", Q_NULLPTR));
        actionToggleBreakpoint->setShortcut(QApplication::translate("MainWindow", "F9", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
        actionShowLST->setText(QApplication::translate("MainWindow", "Open .LST File", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New..", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Create New File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionShowDM->setText(QApplication::translate("MainWindow", "Data Memory Watch", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowDM->setToolTip(QApplication::translate("MainWindow", "Watch Data Memory Content", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShowPM->setText(QApplication::translate("MainWindow", "Program Memory Watch", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowPM->setToolTip(QApplication::translate("MainWindow", "Watch Program Memory Content", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionStopProgram->setText(QApplication::translate("MainWindow", "Stop Program", Q_NULLPTR));
        actionShowRegisters->setText(QApplication::translate("MainWindow", "Registers Watch", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowRegisters->setToolTip(QApplication::translate("MainWindow", "Watch Registers Content", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShowRAM->setText(QApplication::translate("MainWindow", "RAM Watch", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionShowRAM->setToolTip(QApplication::translate("MainWindow", "Watch Internal RAM Content", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionFirmwareWatch->setText(QApplication::translate("MainWindow", "Firmware Watch", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionFirmwareWatch->setToolTip(QApplication::translate("MainWindow", "Watch Firmware HEX Content", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuProgram->setTitle(QApplication::translate("MainWindow", "Program", Q_NULLPTR));
        menuMemory->setTitle(QApplication::translate("MainWindow", "Memory", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
