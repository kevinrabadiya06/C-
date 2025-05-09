//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN

#include<iostream>
#include<cmath>
using namespace std;

class complex{
    private:
    float r=0,i=0;

    public:
    void getdata()
    {
        cout<<"Enter real part:";
        cin>>r;
        cout<<"Enter imaginary part:";
        cin>>i;
    }

    void putdata()
    {
        r=ceil(r*100)/100;
        i=ceil(i*100)/100;
        if(i<0)
        {
            cout<<r<<i<<"i";
        }
        else
        {
            cout<<r<<"+"<<i<<"i";
        }
    }

    complex operator+ (const complex &c)
    {
        complex temp;
        temp.r=r+c.r;
        temp.i=i+c.i;
        return temp;
    }
    complex operator- (const complex &c)
    {
        complex temp;
        temp.r=r-c.r;
        temp.i=i-c.i;
        return temp;
    }
    complex operator* (const complex &c)
    {
        complex temp;
        temp.r=(r*c.r)-(i*c.i);
        temp.i=(r*c.i)+(i*c.r);
        return temp;
    }
    complex operator/ (const complex &c)
    {
        complex temp;
        temp.r=( (r*c.r)+(i*c.i) )/( pow(c.r,2)+pow(c.i,2));
        temp.i=((i*c.r)-(r*c.i))/ ( pow(c.r,2)+pow(c.i,2) );
        return temp;
    }
    complex operator! ()
    {
        complex temp;
        temp.r=r-2*r;
        temp.i=i-2*i;
        return temp;
    }

};

int main()
{
    complex c1,c2,c3;
    string choice;
    c1.getdata();
    c2.getdata();

    cout<<"Choose Operation:"<<endl<<"(+)addition"<<endl<<"(-)Substraction"<<endl<<"(*)Multiplication"<<endl<<"(/)Division"<<endl<<"(!)Negation"<<endl<<"Enter your choice:";
    cin>>choice;
    cin.clear();

    if(choice=="+")
    {
        c3=c1+c2;
        c3.putdata();
    }
    else if(choice=="-")
    {
        c3=c1-c2;
        c3.putdata();
    }
    else if(choice=="*")
    {
        c3=c1*c2;
        c3.putdata();
    }
    else if(choice=="/")
    {
        c3=c1/c2;
        c3.putdata();
    }
    else if(choice=="!")
    {
        c3=!(c1);
        c3.putdata();
        cout<<endl;
        c3=!(c2);
        c3.putdata();
    }
    else
    {
        cout<<"Please enter a valid option";
    }
    return 0;
}
