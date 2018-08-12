#ifndef STUDENT_H
#define STUDENT_H

#include "LIBUSER.h"

class Student: public User{
private:

public:
    Student(){};
    Student(const Student &s)
    {
        userName = s.userName;
        id = s.id;
        noOfLibraryCards = s.noOfLibraryCards;
        canBorrowBooksForMonths = s.canBorrowBooksForMonths;
        borrowed = s.borrowed;
    }
    Student(string Name,int uid,int noOfCards,int BorrowMonths, int br)
    {
        userName = Name;
        id = uid;
        noOfLibraryCards = noOfCards;
        canBorrowBooksForMonths = BorrowMonths;
        borrowed = br;
    }
    void getNoOfCards(){}
    void getIssuingPeriod(){}
    bool canBorrow(){return !borrowed;}
    void Borrowd(){borrowed = true;}
    void returned(){borrowed = false;}
    void showStatus()
    {
        cout<<userName<<id<<noOfLibraryCards<<canBorrowBooksForMonths<<borrowed<<endl;
    }
};

#endif
