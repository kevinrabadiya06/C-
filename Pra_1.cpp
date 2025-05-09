// 23cs080, rabadiya kevin

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string subject[3],id,name;
    int semester,t_marks[3],p_marks[3],credit[3];
    string t_grade[3],p_grade[3];
    int t_grade_point[3],p_grade_point[3];
    float total_credits=0,sum=0,sgpa;
    cout<<"Student id\t:";
    cin>>id;

    cout<<"Student name\t:";
    cin.ignore();
    getline(cin,name);

    cout<<"Semester\t:";
    cin>>semester;

    cout<<"Enter details of three subjects"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<endl<<"Enter subject name:";
        cin.ignore();
        getline(cin,subject[i]);
        cout<<"Theory marks:";
        cin>>t_marks[i];
        cout<<"Practical marks:";
        cin>>p_marks[i];
        cout<<"Credit of the subject:";
        cin>>credit[i];
        if(t_marks[i]<0 || t_marks[i]>100 || p_marks[i]<0 || p_marks[i]>100 || credit[i]<0)
        {
            cout<<"Please enter valid marks";
            return 0;
        }
    }
    for(int i=0;i<3;i++)
    {
        if(t_marks[i]>=80)
        {
            t_grade[i]="AA";
            t_grade_point[i]=10;
        }
        else if(t_marks[i]>=73)
        {
            t_grade[i]="AB";
            t_grade_point[i]=9;
        }
        else if(t_marks[i]>=66)
        {
            t_grade[i]="BB";
            t_grade_point[i]=8;
        }
        else if(t_marks[i]>=60)
        {
            t_grade[i]="BC";
            t_grade_point[i]=7;
        }
        else if(t_marks[i]>=55)
        {
            t_grade[i]="CC";
            t_grade_point[i]=6;
        }
        else if(t_marks[i]>=50)
        {
            t_grade[i]="CD";
            t_grade_point[i]=5;
        }
        else if(t_marks[i]>=45)
        {
            t_grade[i]="DD";
            t_grade_point[i]=4;
        }
        else
        {
            t_grade[i]="FF";
            t_grade_point[i]=0;
        }



        if(p_marks[i]>=80)
        {
            p_grade[i]="AA";
            p_grade_point[i]=10;
        }
        else if(p_marks[i]>=73)
        {
            p_grade[i]="AB";
            p_grade_point[i]=9;
        }
        else if(p_marks[i]>=66)
        {
            p_grade[i]="BB";
            p_grade_point[i]=8;
        }
        else if(p_marks[i]>=60)
        {
            p_grade[i]="BC";
            p_grade_point[i]=7;
        }
        else if(p_marks[i]>=55)
        {
            p_grade[i]="CC";
            p_grade_point[i]=6;
        }
        else if(p_marks[i]>=50)
        {
            p_grade[i]="CD";
            p_grade_point[i]=5;
        }
        else if(p_marks[i]>=45)
        {
            p_grade[i]="DD";
            p_grade_point[i]=4;
        }
        else
        {
            p_grade[i]="FF";
            p_grade_point[i]=0;
        }
    }
    for(int i=0;i<3;i++)
    {
        sum+=credit[i]*((t_grade_point[i]+p_grade_point[i])/2);
        total_credits+=credit[i];
    }
    sgpa=sum/total_credits;

    //OUTPUT
    cout<<endl<<endl<<"Student ID\t:"<<id<<endl;
    cout<<"Student name\t:"<<name<<endl;
    cout<<"Semester\t:"<<semester<<endl;

    cout<<setw(50)<<"Theory\tPractical"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<subject[i]<<setw(40)<<t_grade[i]<<"\t"<<p_grade[i]<<endl;
    }
    cout<<endl<<"S.G.P.A\t\t:"<<sgpa;

}

