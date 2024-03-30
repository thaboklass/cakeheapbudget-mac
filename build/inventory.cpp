#include "inventory.h"
#include <iostream>
/*
Inventory::Inventory(ItemList iList):
itsIList(iList)
{
}

Inventory::Inventory(Items item)
{
    addItem(item);
}

ItemList Inventory::getItems() const
{
    return itsIList;
}


void Inventory::deleteItems()
{
    for (int i = itsIList.size(); i > 0; i--)
        itsIList.pop_back();
}

Items Inventory::getItem(string IDCode) const
{
    Items defaultItem("Item does not exist", 0, 0, "0000");
    bool found = false;
    for (int i = 0; i < itsIList.size(); i++)
    {
        Items inquiredItem = itsIList.at(i);
        cout << inquiredItem.getIDCode();
        if (IDCode == inquiredItem.getIDCode())
        {
            found = true;
            return inquiredItem;
        }
    }
    if (!found)
        return defaultItem;
}

void Inventory::addItem(Items item)
{
    itsIList.push_back(item);
}

void Inventory::removeItem(string IDCode)
{
    int i = 0;
    for (ItemList::iterator ci = itsIList.begin();
            ci != itsIList.end(); ci++)
    {
        Items inquiredItem = itsIList.at(i);
        cout << inquiredItem.getIDCode() << endl;
        if (IDCode == inquiredItem.getIDCode())
        {
            //cout << inquiredItem.getIDCode() << endl;
            itsIList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }
}
*/
