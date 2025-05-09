//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN
#include<iostream>
using namespace std;

string Letter_grade(int data)
{
    if(data>=80)
    return "AA";
    else if(data>=73)
    return "AB";
    else if(data>=66)
    return "BB";
    else if(data>=60)
    return "BC";
    else if(data>=55)
    return "CC";
    else if (data>=50)
    return "CD";
    else if(data>=45)
    return "DD";
    else
    return "FF";
}
int grade_point(int data)
{
    if(data>=80)
    return 10;
    else if(data>=73)
    return 9;
    else if(data>=66)
    return 8;
    else if(data>=60)
    return 7;
    else if(data>=55)
    return 6;
    else if (data>=50)
    return 5;
    else if(data>=45)
    return 4;
    else
    return 0;
}

class result{
    private:
    friend class student;

    string subject[3];
    int credit[3];
    int theory_marks[3],practical_marks[3];
    string theory_grade[3],practical_grade[3];
    int theory_grade_point[3],practical_grade_point[3];
    float SGPA;
};

class student{
    private:
    string id,name;
    int semester;

    public:
    void get_stu_data()
    {
        cout<<"Enter student id :";
        getline(cin,id);
        cin.clear();

        cout<<"Enter student name :";
        getline(cin,name);
        cin.clear();

        cout<<"Enter the semester of the student :";
        cin>>semester;
    }
    void put_stu_data()
    {
        cout<<"Student ID\t:"<<id<<endl;
        cout<<"Student name\t:"<<name<<endl;
        cout<<"Semester\t:"<<semester<<endl;
    }
    void get_result_data(result &r)
    {
        for(int i=0;i<3;i++)
        {
            cout<<endl<<endl<<"Enter the details of subject "<<i+1<<endl<<endl;
            cout<<"Enter subject name :";
            cin.ignore();
            getline(cin,r.subject[i]);
            cout<<"Enter the credit of the subject :";
            cin>>r.credit[i];
            cout<<"Enter the theory marks of the subject :";
            cin>>r.theory_marks[i];
            cout<<"Enter the practical marks of the subject :";
            cin>>r.practical_marks[i];
        }
    }
    void calculate(result &r)   //ADDITIONAL FUNCTION FOR BETTER CODE READABILITY
    {
        for(int i=0;i<3;i++)
        {
            r.theory_grade[i]=Letter_grade(r.theory_marks[i]);
            r.theory_grade_point[i]=grade_point(r.theory_marks[i]);
            r.practical_grade[i]=Letter_grade(r.practical_marks[i]);
            r.practical_grade_point[i]=grade_point(r.practical_marks[i]);
        }

        //SGPA calculation
        float numerator=0,denominator=0;
        for(int i=0;i<3;i++)
        {
            numerator+=r.credit[i] * ( (r.theory_grade_point[i]+r.practical_grade_point[i]) / 2 );
            denominator+=r.credit[i];
        }
        r.SGPA=numerator/denominator;
    }
    void put_result_data(result &r)
    {
        cout<<"\t\t\t\t\t"<<"Theory\tPractical"<<endl;
        for(int i=0;i<3;i++)
        {
            cout<<r.subject[i]<<"\t\t\t\t\t"<<r.theory_grade[i]<<"\t"<<r.practical_grade[i]<<endl;
        }
        cout<<endl<<"SGPA\t:"<<r.SGPA;
    }
};

int main()
{
    student s;
    result r;

    s.get_stu_data();
    s.get_result_data(r);
    s.calculate(r);
    system("cls");
    s.put_stu_data();
    s.put_result_data(r);
}
