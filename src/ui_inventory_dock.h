/********************************************************************************
** Form generated from reading UI file 'inventory_dock.ui'
**
** Created: Sat 12. Jun 07:38:02 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_DOCK_H
#define UI_INVENTORY_DOCK_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCalendarWidget>
#include <QDockWidget>
#include <QHeaderView>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QScrollArea>
#include <QTableWidget>
#include <QWidget>
#include "cake_calenderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_InventoryDock
{
public:
    QWidget *dockWidgetContents;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *inventoryTable;
    QLabel *inventoryLabel;
    QPushButton *addButton;
    CakeCalendarWidget *calendar;
    //QProgressBar *progressBar;

    void setupUi(QDockWidget *InventoryDock)
    {
        if (InventoryDock->objectName().isEmpty())
            InventoryDock->setObjectName(QString::fromUtf8("InventoryDock"));
        InventoryDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(670, 130, 75, 32));
        /*QIcon icon;
        icon.addFile(QString::fromUtf8("images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setIconSize(QSize(30, 18));*/
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(670, 90, 75, 32));
        /*QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);
        editButton->setIconSize(QSize(34, 24));*/
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 598));
        inventoryTable = new QTableWidget(scrollAreaWidgetContents);
        if (inventoryTable->columnCount() < 4)
            inventoryTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        inventoryTable->setObjectName(QString::fromUtf8("inventoryTable"));
        inventoryTable->setGeometry(QRect(10, 40, 581, 541));
        inventoryTable->setColumnWidth(0, 120);
        inventoryTable->setColumnWidth(1, 218);
        inventoryTable->setColumnWidth(2, 120);
        inventoryTable->setColumnWidth(3, 120);
        inventoryLabel = new QLabel(scrollAreaWidgetContents);
        inventoryLabel->setObjectName(QString::fromUtf8("inventoryLabel"));
        inventoryLabel->setGeometry(QRect(18, 5, 571, 31));
        inventoryLabel->setStyleSheet(QString::fromUtf8("font: 18pt \"Helvetica Neue\";"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(670, 50, 75, 32));
        /*QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setIconSize(QSize(32, 22));*/
        calendar = new CakeCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(600, 440, 221, 151));
        /*progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 32));
        progressBar->setValue(24);*/
        InventoryDock->setWidget(dockWidgetContents);

        retranslateUi(InventoryDock);

        QMetaObject::connectSlotsByName(InventoryDock);
    } // setupUi

    void retranslateUi(QDockWidget *InventoryDock)
    {
        InventoryDock->setWindowTitle(QApplication::translate("InventoryDock", "Inventory", 0));
        deleteButton->setText(QApplication::translate("InventoryDock", "Delete", 0));
        editButton->setText(QApplication::translate("InventoryDock", "Edit", 0));
        QTableWidgetItem *___qtablewidgetitem = inventoryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryDock", "IDCode", 0));
        QTableWidgetItem *___qtablewidgetitem1 = inventoryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryDock", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = inventoryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InventoryDock", "No. Items", 0));
        QTableWidgetItem *___qtablewidgetitem3 = inventoryTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("InventoryDock", "Price", 0));
        inventoryLabel->setText(QApplication::translate("InventoryDock", "   Inventory", 0));
        addButton->setText(QApplication::translate("InventoryDock", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryDock: public Ui_InventoryDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORY_DOCK_H
