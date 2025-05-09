//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN
#include<iostream>
using namespace std;

class product{
    protected:
    int id;
    float price;
    string name,manufacturer;

    public:
    product(int a,string b,string c,float d) : id(a),name(b),manufacturer(c),price(d) {}
    virtual void put_data()=0;
};

class smartwatch : public product{
    private:
    float dial_size;

    public:
    smartwatch (int a,string b,string c,float d, float n): dial_size(n) , product(a,b,c,d) {}

    void put_data()
    {
        cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
        cout<<id<<" : "<<name<<" : "<<manufacturer<<" : "<<price<<" : "<<dial_size<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
    }
};

class bedsheet : public product{
    private:
    float height ,width;

    public:
    bedsheet(int a,string b,string c,float d, float h,float w) : product(a,b,c,d) , height(h) , width(w) {}

    void put_data()
    {
        cout<<endl<<"-----------------------------------------------------------------------------------------------------------"<<endl;
        cout<<id<<" : "<<name<<" : "<<manufacturer<<" : "<<price<<" : "<<width<<" : "<< height <<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
    }
};


int main()
{
    int choice;
    int id;
    float price;
    string name,manufacturer;
    float height ,width;
    float dial_size;

    cout<<"[1]Smart watch menu"<<endl<<"[2]Bedsheet menu"<<endl<<"Enter your choice :";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            cout<<endl<<"*******"<<" ENTER SMART WATCH DATA "<<"*******";
            cout<<endl<<endl<<"Enter product id :";
            cin>>id;
            cout<<"Enter product name :";
            cin.ignore();
            getline(cin,name);
            cin.clear();
            cout<<"Enter product manufacturer :";
            getline(cin,manufacturer);
            cin.clear();
            cout<<"Enter product prize :";
            cin>>price;

            cout<<"Enter product dial size :";
            cin>>dial_size;

            smartwatch *s=new smartwatch(id,name,manufacturer,price,dial_size);
            s->put_data();

            break;
        }
        case 2:
        {
            cout<<endl<<"*******"<<" ENTER BEDSHEET DATA "<<"*******";
            cout<<endl<<endl<<"Enter product id :";
            cin>>id;
            cout<<"Enter product name :";
            cin.ignore();
            getline(cin,name);
            cin.clear();
            cout<<"Enter product manufacturer :";
            getline(cin,manufacturer);
            cin.clear();
            cout<<"Enter product prize :";
            cin>>price;

            cout<<"Enter bedsheet Width :";
            cin>>width;
            cout<<"Enter bedsheet height :";
            cin>>height;

            bedsheet *b=new bedsheet(id,name,manufacturer,price,height,width);
            b->put_data();

            break;
        }
        default:
        {
            cout<<"Please enter correct value";
            return 0;
        }
    }
}
