#ifndef ADD_INCOME_BUTTON_H_INCLUDED
#define ADD_INCOME_BUTTON_H_INCLUDED
#include <QPushButton>
class AddIncomeButton : QPushButton
{
    public:
        AddIncomeButton(QWidget *parent = 0);
        void mouseReleaseEvent(MouseEvent *e);
}


#endif // ADD_INCOME_BUTTON_H_INCLUDED
