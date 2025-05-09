// 23cs080, rabadiya kevin

#include<iostream>
using namespace std;
class area
{
float r;
static int count;
public:
    area()
    {
      r=1;
      cout<<"circle with radius "<<r<<" has area "<<3.148*r*r<<endl;
      count++;
    }
    area(float r)
    {
        cout<<"circle with radius "<<r<<" has area "<<3.148*r*r<<endl;
        count++;
    }
    area(area &a)
    {
        cout<<"circle with radius "<<a<<" has area "<<3.148*a*a<<endl;
        count++;
    }
    ~area()
    {
        count--;
        cout<<"one object is deleted"<<endl;
        cout<<"total active object is:"<<count<<endl;
    }
};
int area::count;
int main()
{
    class area a1,a2(20),a3(a2);
}
