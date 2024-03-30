/**
 CakeHeap Budget for Mac
 debt.h
 Purpose: The Inventory class
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

class Items
{
    public:
        Items(string name, double price, int number, string itemID):itsName(name),
            itsPrice(price), itsNumber(number), itsItemID(itemID), itsIDCode(0) {}
        ~Items() {}
        string getName() const { return itsName; }
        void setName(string name) { itsName = name; }
        double getPrice() const { return itsPrice; }
        void setPrice(double price) { itsPrice = price; }
        int getNumber() const { return itsNumber; }
        void setNumber(int number) { itsNumber = number; }
        string getItemID() const { return itsItemID; }
        void setItemID(string itemID) { itsItemID = itemID; }
        int getIDCode() const { return itsIDCode; }
        void setIDCode(int IDCode) { itsIDCode = IDCode; }
    private:
        string itsName;
        double itsPrice;
        int itsNumber;
        string itsItemID;
        int itsIDCode;
};

typedef vector<Items> ItemList;

class Inventory
{
    public:
        Inventory(ItemList iList);
        Inventory(Items item);
        ~Inventory() {}
        ItemList getItems() const;
        void deleteItems();
        Items getItem(string IDCode) const;
        void addItem(Items item);
        void removeItem(string IDCode);
    private:
        ItemList itsIList;
};


#endif // INVENTORY_H_INCLUDED
