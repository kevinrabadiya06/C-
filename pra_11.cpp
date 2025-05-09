//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float month_to_decimal(int n)
{
    float ans=float(100*n)/1200;
    return ans;
}

class employee{

    private:
    int year,months;
    float num;
    public:
    operator float()
    {
        return num;
    }
    void get_data()
    {
        cout<<"Enter employee experience in years and months"<<endl;
        cout<<"Years :";
        cin>>year;
        cout<<"Months :";
        cin>>months;
    }
    void process()
    {
        num+=year;
        float decimal=month_to_decimal(months);
        num+=decimal;
    }
};

int main()
{
    employee e;
    e.get_data();
    e.process();

    float num=e;

    cout<<"Employee experience is :"<<setprecision(4)<<num;
}
