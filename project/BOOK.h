#ifndef BOOK_H
#define BOOK_H

class book{
private:
    int serialNo;
    string bookName;
    int edition;
    string authorName;
    int totalNoOfBooks;
    int booksOccupied;
public:
    book(){}
    book(const book &b)
    {
        serialNo = b.serialNo;
        bookName = b.bookName;
        edition = b.edition;
        authorName = b.authorName;
        totalNoOfBooks = b.totalNoOfBooks;
    }
    book(int sn,string bName,int ed,string aName,int totalBooks)
    {
        serialNo = sn;
        bookName = bName;
        edition = ed;
        authorName = aName;
        totalNoOfBooks = totalBooks;
    }
    void print(){cout<<serialNo<<bookName<<edition<<authorName<<totalNoOfBooks<<endl;}
    void borrowdOne(){booksOccupied++;}
    int getSN(){return serialNo;}
    bool available(){return totalNoOfBooks-booksOccupied;}
    void bookReturned(){totalNoOfBooks++;}
};

#endif
