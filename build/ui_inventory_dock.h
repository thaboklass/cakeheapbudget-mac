/********************************************************************************
** Form generated from reading UI file 'inventory_dock.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_DOCK_H
#define UI_INVENTORY_DOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

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
    QCalendarWidget *calendar;
    QProgressBar *progressBar;

    void setupUi(QDockWidget *InventoryDock)
    {
        if (InventoryDock->objectName().isEmpty())
            InventoryDock->setObjectName(QStringLiteral("InventoryDock"));
        InventoryDock->resize(825, 620);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        deleteButton = new QPushButton(dockWidgetContents);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 130, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setIconSize(QSize(30, 18));
        editButton = new QPushButton(dockWidgetContents);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 90, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);
        editButton->setIconSize(QSize(34, 24));
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
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
        inventoryTable->setObjectName(QStringLiteral("inventoryTable"));
        inventoryTable->setGeometry(QRect(10, 40, 581, 541));
        inventoryLabel = new QLabel(scrollAreaWidgetContents);
        inventoryLabel->setObjectName(QStringLiteral("inventoryLabel"));
        inventoryLabel->setGeometry(QRect(14, 5, 571, 31));
        inventoryLabel->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        addButton = new QPushButton(dockWidgetContents);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 50, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setIconSize(QSize(32, 22));
        calendar = new QCalendarWidget(dockWidgetContents);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 220, 151));
        progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 118, 23));
        progressBar->setValue(24);
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
