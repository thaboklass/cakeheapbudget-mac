#ifndef INVENTORY_DOCK_H_INCLUDED
#define INVENTORY_DOCK_H_INCLUDED
#include <QDockWidget>
#include "ui_inventory_dock.h"
class InventoryDock : public QDockWidget, public Ui::InventoryDock
{
    Q_OBJECT
public:
    InventoryDock(QWidget *parent = 0);
    void resizeEvent(QResizeEvent * event);
private:
    int originalWidth;
    int originalHeight;

    int inventoryIDCodeColumnWidth;
    int inventoryNameColumnWidth;
    int inventoryNumberOfItemsColumnWidth;
    int inventoryPriceColumnWidth;
};


#endif // INVENTORY_DOCK_H_INCLUDED
