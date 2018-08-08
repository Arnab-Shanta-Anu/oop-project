#ifndef LIBUSER_H
#define LIBUSER_H

class User{
private:
    string userName;
    int id;
    int noOfLibraryCards;
    int canBorrowBooksForHowManyMonths;
public:
    virtual void getNoOfCards() = 0;
    virtual void getIssuingPeriod() =0;
};

#endif
