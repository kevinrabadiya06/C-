// 23cs080, rabadiya kevin

#include<iostream>
#include<string.h>
using namespace std;
void area(float r)
{
    cout<<"area of circle is"<<3.14*r*r<<endl;
}
void area(float l,float w)
{
    cout<<"area of rectangle is"<<l*w<<endl;
}
void area(float L,float W,float H)
{
    cout<<"area of cuboid is"<<2*((L*W)+(W*H)+(L*H))<<endl;
}
int main()
{
    int ch,k;
    cout<<"press a index key to find area of following choice"<<endl;
    cout<<" 1. circle"<<endl<<" 2. rectangle"<<endl<<" 3. cuboid"<<endl;
    top:
    cin>>ch;
    switch(ch)
    {
        case 1:
           float r;
           cout<<"enter a radius:";
           cin>>r;
           area(r);
           cout<<endl;
           break;
        case 2:
            float l,w;
            cout<<"enter a length and width:";
            cin>>l>>w;
            area(l,w);
            cout<<endl;
            break;
        case 3:
            float L,W,H;
            cout<<"enter a length,width and height:";
            cin>>L>>W>>H;
            cout<<endl;
            area(L,W,H);
            break;
        default:
            cout<<"enter a valid choice"<<endl;
            break;
    }
    cout<<"press a key '1' to another find a area"<<endl;
    cin>>k;
    if(k==1)
    {
        goto top;
    }
}
