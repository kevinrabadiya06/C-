//THIS PROGRAM IS PREPARED BY 23CS080 KEVIN RABADIYA

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class employee{
    private:
    int id;
    string name,qualification;
    long long mobile_no=0;
    float experience;
    static float avg_exp;

    public:
    static void avg_experience()
    {
        avg_exp=sum_experience/obj;
        cout<<"The average experience of all employees is "<<avg_exp<<endl;
    }


    protected:
    static float obj;
    static float sum_experience;

    int search_id()
    {
        return id;
    }

    void getdata()
    {
        cout<<"Enter employee id: ";
        cin>>id;
        if(id<1000 || id>9999)
        {
            cout<<endl<<"****************************************"<<endl<<endl<<"Please enter a 4 digit employee id"<<endl<<endl<<"****************************************"<<endl;
            exit(0);
        }

        cout<<"Enter your name: ";
        cin.ignore();
        getline(cin,name);

        cout<<"Enter your qualification: ";
        cin.clear();
        getline(cin,qualification);

        cout<<"Enter your experince: ";
        cin>>experience;
        sum_experience+=experience;

        cout<<"Enter your contact number: ";
        cin>>mobile_no;

        if(mobile_no<pow(10,9))
        {
            cout<<"Please enter correct mobile number";
            exit(0);
        }
    }

    void putdata()
    {
        cout<<"Employee name\t:"<<name<<endl;
        cout<<"Qualification\t:"<<qualification<<endl;
        cout<<"Experince\t:"<<experience<<endl;
        cout<<"Contact number\t:"<<mobile_no<<endl;
    }

};

class Teaching_employee : public employee{
    private:
    string designation,specialization,pay_scale;

    public:

    bool search_id(int &data)
    {
        if(data==employee::search_id())
        return true;
        else
        return false;
    }

    void getdata()
    {
        obj++;

        employee::getdata();

        cin.ignore();
        cout<<"Enter your designation: ";
        cin.clear();
        getline(cin,designation);
        cout<<"Enter your specialization: ";
        cin.clear();
        getline(cin,specialization);
        cout<<"Enter your pay scale: ";
        cin.clear();
        getline(cin,pay_scale);
        cout<<endl<<"-----------------------------------------"<<endl<<endl;
    }

    void putdata()
    {
        employee::putdata();

        cout<<"Designation\t:"<<designation<<endl;
        cout<<"Specialization\t:"<<specialization<<endl;
        cout<<"Pay scale\t:"<<pay_scale<<endl;
        cout<<endl<<"-----------------------------------------"<<endl<<endl;
    }



};

class Non_teaching_employee : public employee{
    private:
    long salary;

    public:

    bool search_id(int &data)
    {
        if(data==employee::search_id())
        return true;
        else
        return false;
    }

    void get_non_teaching_employee_data()
    {
        obj++;

        employee::getdata();

        cout<<"Enter your salary: ";
        cin>>salary;
        if(salary<1000 || salary>30000)
        {
            cout<<"The salary ranges between 1000 to 30,000"<<endl<<"Please enter correct value";
            exit(0);
        }
        cout<<endl<<"-----------------------------------------"<<endl<<endl;
    }
    void put_non_teaching_employee_data()
    {
       employee:: putdata();

        cout<<"Salary\t\t:"<<salary<<endl;
        cout<<endl<<"-----------------------------------------"<<endl<<endl;
    }
};

float employee:: avg_exp;
float employee:: sum_experience;
float employee:: obj;

int main()
{
    int non_teachers,teachers;

    cout<<"How many employees are teachers:";
    cin>>teachers;
    cout<<"How many employees are not teachers:";
    cin>>non_teachers;
    if(teachers<0 || teachers>500 || non_teachers<0 || non_teachers>500)
    {
        cout<<"There can only be 500 employees at maximum in each division"<<endl<<"Please enter correct value";
        exit(0);
    }
    cout<<endl<<"-----------------------------------------"<<endl<<"WARNING : YOU MUST ENTER UNIQUE EMPLOYEE IDENTIFICATIONS FOR EACH EMPLOYEE REGARDLESS OF THEIR DIVISION"<<endl<<"-----------------------------------------"<<endl<<endl;
    Teaching_employee temp[teachers];
    Non_teaching_employee non_temp[non_teachers];

    cout<<"Enter the data of teaching employees"<<endl<<endl;
    for(int i=0;i<teachers;i++)
    {
        temp[i].getdata();
    }
    cout<<endl<<"-----------------------------------------"<<endl<<endl;

    cout<<"Enter the data of non teaching employees"<<endl<<endl;
    for(int i=0;i<non_teachers;i++)
    {
        non_temp[i].get_non_teaching_employee_data();
    }

//OUTPUT
    output:

    int *employee_id=new int;
    cout<<"To retrive the the details of the employees"<<endl<<"Enter an employee id:";
    cin>>*employee_id;
    if(*employee_id<1000)
    {
        cout<<endl<<"****************************************"<<endl<<endl<<"ERROR:ENTERED EMPLOYEE ID DOES NOT EXIST"<<endl<<endl<<"****************************************"<<endl;
        exit(0);
    }
    cout<<endl<<"----------------------------------------"<<endl<<endl;

    bool flag_output=false;

    for(int i=0;i<teachers;i++)
    {
        bool flag=temp[i].search_id(*employee_id);
        if(flag==true)
        {
            temp[i].putdata();
            flag_output=true;
            break;
        }
    }
    if(flag_output==false)
    {
        for(int i=0;i<non_teachers;i++)
        {
            bool flag=non_temp[i].search_id(*employee_id);
            if(flag==true)
            {
                non_temp[i].put_non_teaching_employee_data();
                break;
            }

            if(i==(non_teachers-1))
            {
                cout<<"Employee ID:"<<*employee_id<<" does not exist on database"<<endl<<"Please enter correct value"<<endl<<endl;
                goto output;
            }
        }
    }

//SELECT
    select:
    char *choice=new char;
    cout<<"Press Y to get another employee detail,press N to exit:";
    cin>>*choice;
    cin.clear();
    if(*choice=='Y')
    {
        delete employee_id;
        delete choice;
        goto output;
    }
    else if(*choice=='N')
    {
        delete employee_id;
        delete choice;
        employee ::avg_experience();
        cout<<"THANK YOU";
        exit(0);
    }
    else
    {
        cout<<"Please enter correct option";
        goto select;
    }
    return 0;
}
