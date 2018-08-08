#ifndef UI_H
#define UI_H
using namespace std;

class UI{
private:
    char choice;
public:
    void showUI()
    {
        cout<<"\t\t\tPress 1 to issue book\n";
        cout<<"\t\t\tPress 2 to refund book\n";
        cout<<"\t\t\tPress 3 to reissue book\n";
        cout<<"\t\t\tPress 4 to show user status\n";
        cout<<"\t\t\tPress 'q' for quit\n\n";
        cout<<"\t\t\t:: ";
        cin>>choice;
    }
    char getChoice()
    {
        return choice;
    }
};

#endif
