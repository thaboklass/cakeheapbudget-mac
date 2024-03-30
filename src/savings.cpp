#include "savings.h"

/**
 The constructor for the Savings class.
 
 @param name           the name of the savings.
 @param amount         the savings amount(double).
 @param APR            the APR.
 @param nature         the nature of the savings.
 @param date           the date.
 @param description    the description.
 */
Savings::Savings(string name, double amount, float APR, SavingsNature nature, Date date, string description):
itsName(name),
itsNature(nature),
itsDescription(description),
itsIDCode(0),
itsDate(date),
Asset(amount, true, APR)
{
}


/**
 The constructor for the Savings class.
 
 @param name           the name of the savings.
 @param amount         the savings amount(long).
 @param APR            the APR.
 @param nature         the nature of the savings.
 @param date           the date.
 @param description    the description.
 */
Savings::Savings(string name, long lAmount, float APR, SavingsNature nature, Date date, string description):
itsName(name),
itsNature(nature),
itsDescription(description),
itsIDCode(0),
itsDate(date),
Asset(lAmount, true, APR)
{
}
/*
Savings::~Savings()
{
    delete itsName;
    itsName = 0;
    delete itsDescription;
    itsDescription = 0;
}
*/


/**
 The Savings name getter.
 
 @param            nothing.
 @return itsName   the name of the savings.
 */
string Savings::getName() const
{
    return itsName;
}


/**
 The savings name setter.
 
 @param name  the name of the savings.
 @return      nothing.
 */
void Savings::setName(string name)
{
    itsName = name;
}


/**
 The savings nature getter.
 
 @param               nothing.
 @return itsNature    the nature of the savings.
 */
SavingsNature Savings::getNature() const
{
    return itsNature;
}


/**
 The savings nature setter.
 
 @param nature  the nature of the savings.
 @return        nothing.
 */
void Savings::setNature(SavingsNature nature)
{
    itsNature = nature;
}


/**
 The savings description getter.
 
 @param                  nothing.
 @return itsDescription  the description of the savings.
 */
string Savings::getDescription() const
{
    return itsDescription;
}


/**
 The savings nature setter.
 
 @param description  the description of the savings.
 @return      nothing.
 */
void Savings::setDescription(string description)
{
    itsDescription = description;
}


/**
 The savings 'ID code' getter.
 
 @param             nothing.
 @return itsIDCode  the ID code of the savings.
 */
int Savings::getIDCode() const
{
    return itsIDCode;
}


/**
 The savings 'ID code' setter.
 
 @param IDCode  the ID code of the savings.
 @return        nothing.
 */
void Savings::setIDCode(int IDCode)
{
    itsIDCode = IDCode;
}


/**
 The savings date getter.
 
 @param           nothing.
 @return itsDate  the date of the savings.
 */
Date Savings::getDate()
{
    return itsDate;
}


/**
 The savings date setter.
 
 @param IDCode  the date of the savings.
 @return        nothing.
 */
void Savings::setDate(Date date)
{
    itsDate = date;
}
