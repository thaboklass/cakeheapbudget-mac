#include <QtGui>
#include "inventory_dock.h"
InventoryDock::InventoryDock(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
    originalWidth = width() - 1;
    originalHeight = height() + 1;

    inventoryIDCodeColumnWidth  = inventoryTable->columnWidth(0);
    inventoryNameColumnWidth  = inventoryTable->columnWidth(1) + 24;
    inventoryNumberOfItemsColumnWidth  = 101;
    inventoryPriceColumnWidth  = 101;
    
    inventoryTable->setShowGrid(false);
    inventoryTable->setAlternatingRowColors(true);
    inventoryTable->setStyleSheet("QHeaderView::section { text-align: left; } QTableWidget { border: 0px; gridline-color: #fffff8; color: #1b67ac; font-size: 12pt; alternate-background-color: #d1e4f6; background-color: #ffffff; }");
}

void InventoryDock::resizeEvent(QResizeEvent * event)
{
    int extraWidth = width() - originalWidth;
    int extraHeight = height() - originalHeight;
    //cout << extraWidth << endl;

    deleteButton->setGeometry(670 + extraWidth, 130, 75, 32);
    editButton->setGeometry(670 + extraWidth, 90, 75, 32);
    scrollArea->setGeometry(0, 0, 600 + extraWidth, 620 + extraHeight);
    inventoryTable->setGeometry(10, 40, 581 + extraWidth, 541 + extraHeight);
    addButton->setGeometry(670 + extraWidth, 50, 75, 32);
    calendar->setGeometry(600 + extraWidth, 460 + extraHeight, 221, 160);
    //progressBar->setGeometry(640 + extraWidth, 10, 118, 23);

    inventoryTable->setColumnWidth(0, inventoryIDCodeColumnWidth + extraWidth / 4);
    inventoryTable->setColumnWidth(1, inventoryNameColumnWidth + extraWidth / 4);
    inventoryTable->setColumnWidth(2, inventoryNumberOfItemsColumnWidth + extraWidth / 4);
    inventoryTable->setColumnWidth(3, inventoryPriceColumnWidth + extraWidth / 4);
    
    int individualColumnsWidth = inventoryTable->columnWidth(0) + inventoryTable->columnWidth(1) + inventoryTable->columnWidth(2) + inventoryTable->columnWidth(3);
    
    int widthDifference = inventoryTable->width() - individualColumnsWidth;
    
    if (widthDifference > 0)
        inventoryTable->setColumnWidth(3, inventoryTable->columnWidth(3) + widthDifference);
    
    if (widthDifference < 0)
        inventoryTable->setColumnWidth(3, inventoryTable->columnWidth(3) - widthDifference);
}
