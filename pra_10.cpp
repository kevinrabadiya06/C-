//This program is prepared by 23CS080 RABADIYA KEVIN

#include<iostream>
#include<cmath> //FOR fmod and floor functions

using namespace std;

int value_after_decimal(float n,int num)
{
    float remainder=fmod(n,num);
    remainder*=100;
    int exact=floor(remainder);

    return exact;
}

int number_to_month(float num,int year)
{
    int value_after_point=value_after_decimal(num,year);
    int month=(12*value_after_point)/100;

    return month;
}

class employee{
    private:
    int year,months;

    public:
    employee(float a)
    {
        year=floor(a);
        months=number_to_month(a,year);
    }
    void put_data()
    {
        cout<<"Employee experience is "<<year<<" years and "<<months<<" months.";
    }
};

int main()
{
    float num;
    cout<<"Enter employee experience :";
    cin>>num;
    if(num<1)
    {
        cout<<"Please enter correct value";
        return 0;
    }

    employee e(num); //Same as [ employee e=num; ]
    e.put_data();
}
