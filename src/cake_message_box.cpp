#include "cake_message_box.h"
//#include "main_budget.h"

CakeMessageBox::CakeMessageBox()
{
    setWindowTitle("Reminder");
    setWindowIcon(QIcon("images/cake_heap_icon.png"));
    setStandardButtons(QMessageBox::Ok);
}
