#include "budget_page.h"

/**
 The 'add item' class method - adds a new item
 to the inventory.
 
 @param name           the name of the item.
 @param price          the item's price.
 @param itemID         the item's ID.
 @param APR            the APR.
 @param iList          the item list from the inventory page.
 @return               nothing.
 */
void addItem(string name, double price, int number, string itemID, ItemList &iList)
{
    Items addedItem(name, price, number, itemID);
    // add the income to the vector list
    addedItem.setIDCode(iList.size() + 1);
    iList.push_back(addedItem);
}


/**
 The 'edit item' class method - edits an existing item.
 
 @param name           the name of the item.
 @param price          the item's price.
 @param itemID         the item's ID.
 @param APR            the APR.
 @param iList          the item list from the inventory page.
 @param IDCode         the ID code (unique)
 @return               nothing.
 */
void editItem(string name, double price, int number, string itemID, ItemList &iList, int IDCode) {
    ItemList::iterator ci = iList.begin();
    bool found = false;
    Items editedItem("" , 0 , 0, "");
    for (int i = 0; i < iList.size(); i++)
    {
        editedItem = iList.at(i);
        if (IDCode == editedItem.getIDCode())
        {
            found = true;
            editedItem.setName(name);
            editedItem.setPrice(price);
            editedItem.setNumber(number);
            editedItem.setItemID(itemID);
            iList.erase(ci);
            iList.insert(ci, editedItem);
            break;
        }
        ci++;
    }
}


/**
 The 'delete item' class method - deletes an existing item.
 
 @param iList          the item list from the inventory page.
 @param IDCode         the ID code (unique)
 @return               nothing.
 */
void deleteItem(ItemList &iList, int IDCode) {
    int i = 0;
    for (ItemList::iterator ci = iList.begin();
            ci != iList.end(); ci++)
    {
        Items deletedItem = iList.at(i);
        //cout << inquiredItem.getIDCode() << endl;
        if (IDCode == deletedItem.getIDCode())
        {
            //cout << deletedSavings.getIDCode() << endl;
            iList.erase(ci);
            break;
        }
        //cout << i << endl;
        i++;
    }

    // re-label the new income list after the deletion
    ItemList::iterator ci = iList.begin();
    for (int i = 0; i < iList.size(); i++)
    {
        Items updatedItem = iList.at(i);
        updatedItem.setIDCode(i + 1);
        iList.erase(ci);
        iList.insert(ci, updatedItem);
        ci++;
    }
}

void addItemAgain(string name, double price, int number, string itemID, int IDCode, ItemList &iList)
{
    Items addedItem(name, price, number, itemID);
    // add the income to the vector list
    ItemList::iterator ci = iList.begin();
    addedItem.setIDCode(IDCode);
    iList.insert((ci + IDCode) - 1, addedItem);

    Items editedItem("" , 0 , 0, "");

    ci = ci + IDCode;

    for (int i = IDCode; i < iList.size(); i++)
    {
        editedItem = iList.at(i);
        int currentIDCode = editedItem.getIDCode();
        editedItem.setIDCode(currentIDCode + 1);
        iList.erase(ci);
        iList.insert(ci, editedItem);
        ci++;
    }

}
