//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN

#include<iostream>
using namespace std;

class millimeter;
class centimeter;

class centimeter{
    private:
    float cm;

    public:
    centimeter() : cm(0){}

    centimeter(millimeter &obj);

    void get_data()
    {
        cout<<"Enter measurment in cm : ";
        cin>>cm;
    }
    void put_data()
    {
        cout<<"Measurment in cm : "<<cm;
    }
    float return_value()
    {
        return cm;
    }
};

class millimeter{
    private:
    float mm;

    public:
    millimeter() : mm(0){}
    millimeter(centimeter &obj)
    {
        mm=obj.return_value()*10;
    }

    void get_data()
    {
        cout<<"Enter measurment in mm : ";
        cin>>mm;
    }
    float return_value()
    {
        return mm;
    }
    void put_data()
    {
        cout<<"Measurment in mm : "<<mm;
    }
};

centimeter :: centimeter(millimeter &obj)
{
    cm=(obj.return_value())/10;
}

int main()
{
    int *choice=new int;

    cout<<"[1] mm to cm converter"<<endl<<"[2] cm to mm converter"<<endl<<"Enter your choice :";
    cin>>*choice;

    switch(*choice)
    {
        case 1:
        {
            millimeter m;
            m.get_data();
            centimeter c=m;
            c.put_data();
            break;
        }
        case 2:
        {
            centimeter c;
            c.get_data();
            millimeter m=c;
            m.put_data();
            break;
        }
        default:
        {
            cout<<"Please enter correct option";
            return 0;
        }
    }
}
