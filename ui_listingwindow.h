/********************************************************************************
** Form generated from reading UI file 'listingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTINGWINDOW_H
#define UI_LISTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListingWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListingWindow)
    {
        if (ListingWindow->objectName().isEmpty())
            ListingWindow->setObjectName(QStringLiteral("ListingWindow"));
        ListingWindow->resize(800, 600);
        centralwidget = new QWidget(ListingWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        ListingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ListingWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ListingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ListingWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ListingWindow->setStatusBar(statusbar);

        retranslateUi(ListingWindow);

        QMetaObject::connectSlotsByName(ListingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ListingWindow)
    {
        ListingWindow->setWindowTitle(QApplication::translate("ListingWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ListingWindow: public Ui_ListingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTINGWINDOW_H
