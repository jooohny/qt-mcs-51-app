/********************************************************************************
** Form generated from reading UI file 'regtable.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGTABLE_H
#define UI_REGTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegTable
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *dataBankTable;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QTableWidget *dataSFRtable;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *dataSFRtable_2;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *dataSFRtable_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegTable)
    {
        if (RegTable->objectName().isEmpty())
            RegTable->setObjectName(QStringLiteral("RegTable"));
        RegTable->resize(350, 936);
        centralwidget = new QWidget(RegTable);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dataBankTable = new QTableWidget(centralwidget);
        dataBankTable->setObjectName(QStringLiteral("dataBankTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataBankTable->sizePolicy().hasHeightForWidth());
        dataBankTable->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(dataBankTable);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dataSFRtable = new QTableWidget(centralwidget);
        dataSFRtable->setObjectName(QStringLiteral("dataSFRtable"));

        horizontalLayout->addWidget(dataSFRtable);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        dataSFRtable_2 = new QTableWidget(centralwidget);
        dataSFRtable_2->setObjectName(QStringLiteral("dataSFRtable_2"));

        horizontalLayout_5->addWidget(dataSFRtable_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        dataSFRtable_3 = new QTableWidget(centralwidget);
        dataSFRtable_3->setObjectName(QStringLiteral("dataSFRtable_3"));

        horizontalLayout_6->addWidget(dataSFRtable_3);


        verticalLayout->addLayout(horizontalLayout_6);

        RegTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegTable);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 350, 26));
        RegTable->setMenuBar(menubar);
        statusbar = new QStatusBar(RegTable);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RegTable->setStatusBar(statusbar);

        retranslateUi(RegTable);

        QMetaObject::connectSlotsByName(RegTable);
    } // setupUi

    void retranslateUi(QMainWindow *RegTable)
    {
        RegTable->setWindowTitle(QApplication::translate("RegTable", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegTable", "Data bank", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegTable", "Special functions registers", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegTable: public Ui_RegTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGTABLE_H
