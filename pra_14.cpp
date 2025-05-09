//THIS PROGRAM IS PREPARED BY 23CS080 KEVIN RABADIYA
#include<iostream>
#include<cmath>

using namespace std;
#define MAX_SIZE 100

class literature{
    private:
    int id;
    string title;
    char type_of_literature;
    int stock_copies;
    string DOI;

    protected:
    void getdata()
    {
        cout<<"Enter the id:";
        cin>>id;

        if(id<0 || id>=pow(10,8))
        {
            cout<<"Please enter correct id number ";
            exit(0);
        }

        cout<<"Enter the title:";
        cin.ignore();
        getline(cin,title);
        cin.clear();
        cout<<"(E) e-Literature"<<endl<<"(H) Hard bound literature"<<endl<<"What is the type of literatue :";
        cin>>type_of_literature;

        if(type_of_literature=='E')
        {
            cin.ignore();
            cout<<"Enter the DOI :";
            getline(cin,DOI);
            cin.clear();
        }
        else if(type_of_literature=='H')
        {
            cout<<"Enter the number of copies in the stock:";
            cin>>stock_copies;
        }
        else
        {
            cout<<"Please enter the correct code for literature";
            exit(0);
        }
    }

    void putdata()
    {
        cout<<"ID :"<<id<<endl<<endl;
        cout<<"TITLE :"<<title<<endl;

        if(type_of_literature=='E')
        cout<<"Digital object identifier (DOI) :"<<DOI<<endl;
        else
        cout<<"Stock :"<<stock_copies<<" copies"<<endl;
    }

};

class book : public virtual literature{
    private:
    int ISBN;

    protected:
    void getdata()
    {
        cout<<"Enter the ISBN number:";
        cin>>ISBN;
    }
    void putdata()
    {
        cout<<"ISBN :"<<ISBN;
    }
};

class magazine : public virtual literature{
    private:
    int ISSN;

    protected:
    void getdata()
    {
        cout<<"Enter the ISSN number:";
        cin>>ISSN;
    }
    void putdata()
    {
        cout<<"ISSN :"<<ISSN;
    }

};

class library : public book , public magazine {
    private:
    string type_data;

    public:
    void getdata(const string s)
    {
        type_data=s;

        literature::getdata();

        if(type_data=="book")
        {
            book::getdata();
        }
        else
        {
            magazine::getdata();
        }
        cout<<endl<<endl;
    }
    void putdata()
    {
        literature::putdata();
        if(type_data=="book")
        {
            book::putdata();
        }
        else
        {
            magazine::putdata();
        }
    }

    bool bookdata()
    {
        if(type_data=="book")
        return true;
        else
        return false;
    }
    bool magdata()
    {
        if(type_data=="magazine")
        return true;
        else
        return false;
    }

};

int main()
{
    int choice,count=0;
    library l[MAX_SIZE];

    again:
    cout<<"[0] Exit"<<endl<<"[1] ADD book data"<<endl<<"[2] ADD magazine data"<<endl<<"[3] List all the books"<<endl<<"[4] List all the magazines"<<endl<<"Enter your choice :";
    cin>>choice;

    switch(choice)
    {
        char switch_choice;
        case 0:
        {
            cout<<"THANK YOU";
            return 0;
        }
        case 1:
        {
            cout<<"******************** ADD BOOK DATA ********************"<<endl;
            l[count].getdata("book");

            cout<<"Press M to return to main menu , press any key to exit"<<endl<<"Enter:";
            cin>>switch_choice;
            if(switch_choice=='M')
            {
                count++;
                goto again;
            }
            break;
        }
        case 2:
        {
            cout<<"******************** ADD MAGAZINE DATA ********************"<<endl;
            l[count].getdata("magazine");

            cout<<"Press M to return to main menu , press any key to exit"<<endl<<"Enter:";
            cin>>switch_choice;
            if(switch_choice=='M')
            {
                count++;
                goto again;
            }

            break;
        }
        case 3:
        {
            cout<<"******************** LIST ALL BOOKS ********************"<<endl;
            for(int i=0;i<count;i++)
            {
                if(l[i].bookdata()==true)
                {
                    cout<<endl<<"************************************************************************************"<<endl;
                    l[i].putdata();
                    cout<<endl<<"************************************************************************************"<<endl;
                }
            }
            cout<<"Press M to return to main menu , press any key to exit"<<endl<<"Enter:";
            cin>>switch_choice;
            if(switch_choice=='M')
            {
                goto again;
            }

            break;
        }
        case 4:
        {
            cout<<"******************** LIST ALL MAGAZINES ********************"<<endl;
            for(int i=0;i<count;i++)
            {
                if(l[i].magdata()==true)
                {
                    cout<<endl<<"************************************************************************************"<<endl;
                    l[i].putdata();
                    cout<<endl<<"************************************************************************************"<<endl;
                }
            }
            cout<<"Press M to return to main menu , press any key to exit"<<endl<<"Enter:";
            cin>>switch_choice;
            if(switch_choice=='M')
            {
                goto again;
            }

            break;
        }
        default:
        {
            cout<<"Please enter correct value";
            return 0;
        }
    }
}
