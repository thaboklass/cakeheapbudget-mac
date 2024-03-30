/********************************************************************************
** Form generated from reading UI file 'inventory_page.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_PAGE_H
#define UI_INVENTORY_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inventoryPage
{
public:
    QCalendarWidget *calendar;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QProgressBar *progressBar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *inventoryTable;
    QLabel *inventoryLabel;

    void setupUi(QDialog *inventoryPage)
    {
        if (inventoryPage->objectName().isEmpty())
            inventoryPage->setObjectName(QStringLiteral("inventoryPage"));
        inventoryPage->resize(825, 600);
        calendar = new QCalendarWidget(inventoryPage);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(600, 440, 220, 151));
        addButton = new QPushButton(inventoryPage);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(650, 160, 75, 23));
        QIcon icon;
        icon.addFile(QStringLiteral("add.gif"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 22));
        deleteButton = new QPushButton(inventoryPage);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(650, 240, 75, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral("delete.gif"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(30, 18));
        editButton = new QPushButton(inventoryPage);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(650, 200, 75, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral("edit.gif"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon2);
        editButton->setIconSize(QSize(34, 24));
        progressBar = new QProgressBar(inventoryPage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(650, 20, 118, 23));
        progressBar->setValue(24);
        scrollArea = new QScrollArea(inventoryPage);
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
        QWidget::setTabOrder(scrollArea, inventoryTable);
        QWidget::setTabOrder(inventoryTable, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, calendar);

        retranslateUi(inventoryPage);

        QMetaObject::connectSlotsByName(inventoryPage);
    } // setupUi

    void retranslateUi(QDialog *inventoryPage)
    {
        inventoryPage->setWindowTitle(QString());
        addButton->setText(QApplication::translate("inventoryPage", "Add", 0));
        deleteButton->setText(QApplication::translate("inventoryPage", "Delete", 0));
        editButton->setText(QApplication::translate("inventoryPage", "Edit", 0));
        QTableWidgetItem *___qtablewidgetitem = inventoryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("inventoryPage", "IDCode", 0));
        QTableWidgetItem *___qtablewidgetitem1 = inventoryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("inventoryPage", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = inventoryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("inventoryPage", "No. Items", 0));
        QTableWidgetItem *___qtablewidgetitem3 = inventoryTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("inventoryPage", "Price", 0));
        inventoryLabel->setText(QApplication::translate("inventoryPage", "   Inventory", 0));
    } // retranslateUi

};

namespace Ui {
    class inventoryPage: public Ui_inventoryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORY_PAGE_H
