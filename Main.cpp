///class,object,constructors
///inheritance
//file stream
///multi file
//array,string
///virtual func, friend func
///pointer
//op overloading
//structure,enum
//stl

#include <iostream>
#include <fstream>
#include "ui.h"
#include "BOOK.h"
#include "LIBUSER.h"
#include "STUDENT.h"
#include "TEACHER.h"

int main()
{
    UI *ui = new UI();
    ui->showUI();
    switch(ui->getChoice())
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case 'q':
        break;
    }
    return 0;
}
