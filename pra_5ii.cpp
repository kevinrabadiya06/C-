// 23cs080, rabadiya kevin

#include<iostream>
using namespace std;

const float PI=3.14;

class circle{
    private:
    float radius;
    double area;
    static int count;
    public:
    circle(float r=1)
    {
        radius=r;
        count++;

        area=PI*radius*radius;
        cout<<endl<<"Circle with radius "<<radius<<" has area "<<area;
    }
    circle (circle &c)
    {
        count++;
        radius=c.radius;
        area=PI*radius*radius;
        cout<<endl<<"Circle with radius "<<radius<<" has area "<<area;

    }
    ~circle()
    {
        count--;
        cout<<endl<<"One object is deleted"<<endl<<"total active objects are "<<count;
    }

};
int circle::count;

int main()
{
    int choice;
    cout<<"[1]Static Output"<<endl<<"[2]Dynamic output"<<endl<<"Enter:";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:
        {

            circle c,c1(2.5),c2(c1);
            break;
        }
        case 2:
        {
            circle* c=new circle(5);
            circle* c1=new  circle(10.2);

            delete c1;

            circle c2(*c);
            delete c;
            break;
        }
        default:
        {
            cout<<"Please enter the correct value";
            break;
        }
    }
}
