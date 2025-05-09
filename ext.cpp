#include<iostream>
using namespace std;
int main()
{
cout.fill('*');
cout<<1234<<endl;
cout.width(7);
cout<<"hello"<<endl;
cout.fill('*');
cout.precision(7);
cout.width(10);
cout<<1234.567<<endl;
cout.precision(8);
cout.width(10);
cout<<1234.567<<endl;
cout.precision(5);
cout.width(10);
cout<<1234.567<<endl;
cout.precision(3);
cout.width(10);
cout<<1234.567<<endl;
}
