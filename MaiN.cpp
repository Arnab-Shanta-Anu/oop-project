///class,object,constructors
///inheritance
///file stream
///multi file
///array,string
///virtual func, friend func
///pointer
///stl
//op overloading
//structure,enum

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include "ui.h"
#include "BOOK.h"
#include "LIBUSER.h"
#include "STUDENT.h"
#include "TEACHER.h"

void issueBook(vector<book> Books,vector<Student> users);
void refundBook(vector<book> Books,vector<Student> users);
void reissueBook(vector<book> Books,vector<Student> users);
void src(vector<book> Books);
void userStatus(vector<Student> users);


int main()
{
    ifstream in("Input.txt");
    ifstream userRecord("users.txt");

    int sn;string bName;int ed;string aName;int totalBooks;
    vector<book> Books;

    while(!in.eof()){
        in>>sn;in.ignore();getline(in,bName);in>>ed;in.ignore();getline(in,aName);in>>totalBooks;
        book b(sn,bName,ed,aName,totalBooks);
        Books.push_back(b);
    }

    vector<Student> users;
    string Name;int uid;int noOfCards;int BorrowMonths;int br;
    while(!userRecord.eof()){
        getline(userRecord,Name);userRecord>>uid;userRecord>>noOfCards;userRecord>>br;userRecord>>BorrowMonths;
        Student s(Name,uid,noOfCards,BorrowMonths,br);
        users.push_back(s);
    }

    UI *ui = new UI();
    ui->initUI();

    char choice;
    cin>>choice;

    switch(choice)
    {
        case '1': issueBook(Books,users);
            break;
        case '2': refundBook(Books,users);
            break;
        case '3': reissueBook(Books,users);
            break;
        case '4': src(Books);
            break;
        case '5': userStatus(users);
            break;
        case 'q':
            break;
    }

    in.close();
    userRecord.close();
    return 0;
}

void issueBook(vector<book> Books, vector<Student> users)
{
    cout<<"Enter serial no of Book: ";
    int sn;
    cin>>sn;
    cout<<"Enter your user id: ";
    int uid;
    cin>>uid;
    Student s;
    for(auto x: users){
        if(x.id==uid){
            s = x;
            if(!x.canBorrow()){
                cout<<"you already have borrowed book(s)"<<endl;
                return ;
            }
        }
    }
    book b;
    for(auto x: Books){
        if(x.getSN() == sn){
            b = x;
            if(x.available()){
                cout<<"you have issued the book"<<endl;
                s.Borrowd();
                b.borrowdOne();
            }
            else{
                cout<<"Sorry the book isn't available"<<endl;
                return ;
            }
        }
    }

}

void refundBook(vector<book> Books,vector<Student> users)
{
    cout<<"Enter serial no of Book: ";
    int sn;
    cin>>sn;
    cout<<"Enter your user id: ";
    int uid;
    cin>>uid;
    Student s;
    for(auto x: users){
        if(x.id==uid){
            s = x;
            s.returned();
        }
    }
    book b;
    for(auto x: Books){
        if(x.getSN() == sn){
            b=x;
            b.bookReturned();
        }
    }
}

void reissueBook(vector<book> Books,vector<Student> users)
{
    cout<<"Enter serial no of Book: ";
    int sn;
    cin>>sn;
    cout<<"Enter your user id: ";
    int uid;
    cin>>uid;

    book b; Student s;

    for(auto x: users){
        if(x.id==uid){
            s = x;
        }
    }
    for(auto x: Books){
        if(x.getSN() == sn){
            b=x;
            b.bookReturned();
            b.borrowdOne();
        }
    }
}

void src(vector<book> Books)
{
    cout<<"Enter serial no of Book: ";
    int sn;
    cin>>sn;

    for(auto x: Books){
        if(x.getSN() == sn){
            x.print();
        }
    }
}

void userStatus(vector<Student> users)
{
    cout<<"Enter your user id: ";
    int uid;
    cin>>uid;

    for(auto x: users){
        if(x.id==uid){
            x.showStatus();
        }
    }
}
