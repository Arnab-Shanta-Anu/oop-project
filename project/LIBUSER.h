#ifndef LIBUSER_H
#define LIBUSER_H

class User{
public:
    string userName;
    int id;
    int noOfLibraryCards;
    int canBorrowBooksForMonths;
    bool borrowed;
//public:
    virtual void getNoOfCards() = 0;
    virtual void getIssuingPeriod() =0;
    User(){}
};

#endif
