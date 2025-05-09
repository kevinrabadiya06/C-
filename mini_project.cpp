#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
    time_t t=time(NULL);
    tm* timePtr=localtime(&t);
    int year=timePtr->tm_year+1900;
    int month=timePtr->tm_mon+1;
    int day=timePtr->tm_mday;
    int daysinmonth;

    while(true)
        {
        if(month==2)
        {
            if(year%4==0&&(year%100!=0||year%400==0))
            {
                daysinmonth=29;
            }else
            {
            daysinmonth=28;
            }
        }
        else if(month==4||month==6||month==9||month==11)
            {
            daysinmonth=30;
        }
        else
            {
            daysinmonth=31;
            }
        }

            cout<<setw(24)<<left<<"month: "<<month<<"/";
            cout<< "Sun Mon Tue Wed Thu Fri Sat"<<endl;

            tm firstday;
            firstday.tm_year=year=1900;
            firstday.tm_mon=month=1;
            firstday.tm_mday=1;
            mktime(&firstday);
            int firstdayofweek=firstday.tm_wday;

            int currentday=1;
            for(int i=0;i<6;i++)
                {
                for(int j=0;j<7;j++)
                {
                    if(i==0&&j<firstdayofweek)
                    {
                        cout<<"    ";
                    }
                     else if(currentday>daysinmonth)
                        {
                        cout<<"    ";
                        }
                        else
                            {
                            if(currentday==day)
                            {
                                cout<<setw(2)<<left<<"|"<<currentday;
                            }
                            else
                            {
                                cout<<setw(4)<<left<<currentday;
                            }
                                currentday++;
                            }
                }
                cout<<endl;
                if(currentday>daysinmonth)
                    {
                       break;
                    }
                  }

                     cout<<"Enter a command(n=next month,p=previous month,'any key'=quit"<<endl;
                     char command;
                     cin>>command;
                     if(command == 'n')
                        {
                        month++;
                        if(month>12)
                            {
                            month=1;
                            year++;
                            }
                        }
                      if(command == 'p')
                     {
                     month--;
                     if(month<1)
                        {
                        month=12;
                        year--;
                        }
                     }

                   }

