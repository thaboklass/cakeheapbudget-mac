#ifndef ITEM_DIALOG_H_INCLUDED
#define ITEM_DIALOG_H_INCLUDED
#include <QDialog>
#include "ui_item_dialog.h"
class ItemDialog : public QDialog, public Ui::itemDialog
{
    Q_OBJECT
public:
    ItemDialog(QWidget *parent = 0);
};

#endif // ITEM_DIALOG_H_INCLUDED
