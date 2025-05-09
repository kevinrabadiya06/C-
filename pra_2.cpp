// 23cs080, rabadiya kevin

#include<iostream>
#include<string.h>
using namespace std;
struct employee
{
string name;
string qua;
float exp;
int contact;
}emp;
int main()
{
    int a,id;
    top:
    cout<<"enter employee id"<<endl;
    cin>>id;
    if(id<=999||id>9999)
    {
        cout<<"*****************************"<<endl;
        cout<<"error: employee id not found"<<endl;
        cout<<"*****************************"<<endl;
    }
    else
    {
    cout<<"enter employee name"<<endl;
    cin>>emp.name;
    cout<<"enter employee qualification"<<endl;
    cin>>emp.qua;
    cout<<"enter employee experience (in year)"<<endl;
    cin>>emp.exp;
    cout<<"enter employee contact number"<<endl;
    cin>>emp.contact;
       if(emp.contact<1000000000||emp.contact>10000000000)
       {
         cout<<"***************************"<<endl;;
         cout<<"contact number is invalid"<<endl;
         cout<<"***************************"<<endl;
       }
       else
        {
            cout<<"---------------------------------"<<endl;
            cout<<"employee id:    "<<id<<endl;
            cout<<"employee name:  "<<emp.name<<endl;
            cout<<"qualification:  "<<emp.qua<<endl;
            cout<<"experience:     "<<emp.exp<<endl;
            cout<<"contact number: "<<emp.contact<<endl;
            cout<<"---------------------------------"<<endl;
        }
    }
    cout<<"press key '1' to another employee details"<<endl;
    cin>>a;
    if(a==1)
    {
        goto top;
    }
}
