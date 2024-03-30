#include <QtGui>
#include "donate_dialog.h"
DonateDialog::DonateDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    QImage image("images/cake_heap_icon_half.png");
    donationImage->setPixmap(QPixmap::fromImage(image));
}
