#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
 int first_year(int year)
 {
     int day;
     day=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
     return day;
 }
int main()
{
    int year,day,week;
    int days_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout<<"\n\n Enter Year :";
    cin>>year;
    if(year%4==0)
    {
        days_months[1]=29;
    }
    day=first_year(year);
    system("cls");
    for(int i=0;i<=11;i++)
    {
        cout<<"\n\n\t\t"<<months[i]<<", "<<year;
        cout<<"\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";
        for(int j=0;j<day;j++)
        {
            cout<<"      ";
        }
        week=day;
        for(int m=1;m<=days_months[i];m++)
        {
            if(m<=10)
            {
                cout<<"     ";
            }
            else
            {
                cout<<"    ";
            }
            if(week>6)
            {
                cout<<"\n    "<<m;
                week=0;
            }
            else
            {
                cout<<m;
            }
            week++;
        }
        day=week;
    }
    getch();
    return 0;
}
