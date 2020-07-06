/********************************************************************************
** Form generated from reading UI file 'memorywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYWINDOW_H
#define UI_MEMORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoryWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *memoryTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *editButton;
    QPushButton *eraseButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MemoryWindow)
    {
        if (MemoryWindow->objectName().isEmpty())
            MemoryWindow->setObjectName(QStringLiteral("MemoryWindow"));
        MemoryWindow->resize(464, 302);
        centralwidget = new QWidget(MemoryWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        memoryTable = new QTableWidget(centralwidget);
        memoryTable->setObjectName(QStringLiteral("memoryTable"));

        verticalLayout->addWidget(memoryTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName(QStringLiteral("editButton"));

        horizontalLayout->addWidget(editButton);

        eraseButton = new QPushButton(centralwidget);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));

        horizontalLayout->addWidget(eraseButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);

        MemoryWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MemoryWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 464, 26));
        MemoryWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MemoryWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MemoryWindow->setStatusBar(statusbar);

        retranslateUi(MemoryWindow);

        QMetaObject::connectSlotsByName(MemoryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MemoryWindow)
    {
        MemoryWindow->setWindowTitle(QApplication::translate("MemoryWindow", "MainWindow", Q_NULLPTR));
        editButton->setText(QApplication::translate("MemoryWindow", "Edit", Q_NULLPTR));
        eraseButton->setText(QApplication::translate("MemoryWindow", "Erase", Q_NULLPTR));
        closeButton->setText(QApplication::translate("MemoryWindow", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemoryWindow: public Ui_MemoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYWINDOW_H
