//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class employee{
    private:
    long long mobile_no=0;
    int id;
    string name,qualification;
    float experience;
    static int id_repeat;
    static float sum_experience;
    static float obj;

    public:
    void getdata()
    {
        obj++;
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
        
        cout<<endl<<"-----------------------------------------"<<endl<<endl;
    }
    static void avg_experience_display()
    {
        cout<<"The average experience of all employees is "<<sum_experience/obj<<endl;
    }


    bool check_employee(int &employee_id)
    {
        if(employee_id==id)
        return true;
        else
        return false;
    }

    void putdata() const
    {
        cout<<"Employee name\t:"<<name<<endl;
        cout<<"Qualification\t:"<<qualification<<endl;
        cout<<"Experince\t:"<<experience<<endl;
        cout<<"Contact number\t:"<<mobile_no<<endl;
        cout<<endl<<"-----------------------------------------"<<endl<<endl;
    }
    void id_display() const
    {
        cout<<id<<endl;
    }

    bool dont_repeat() const
    {
        if(obj==1)
        {
            id_repeat=id;
            return true;
        }
        
        if(id==id_repeat)
        {
            cout<<"Every employee must have unique id"<<endl;
            return false;
        }
        else
        return true;
    }

};

float employee:: sum_experience;
float employee:: obj;
int employee :: id_repeat;

int main()
{

//INPUT
    int no_of_employee;
    cout<<"Enter the number of employees:";
    cin>>no_of_employee;
    if(no_of_employee<0 || no_of_employee>1000)
    { 
        cout<<"There maximum capacity is of 1000 employess"<<endl<<"Please enter correct value";  
        exit(0);
    }
    employee e[no_of_employee];

    cout<<"Enter the details of "<<no_of_employee<<" employees"<<endl;
    for(int i=0;i<no_of_employee;i++)
    {
        cout<<"Employee number:"<<i+1<<endl;
        e[i].getdata();
        cin.clear();

        //Checking for repeated same id
        bool flag=e[i].dont_repeat();

        if(flag==false)
        return 0;
    }


//OUTPUT
    output:
    int *employee_id=new int;

    cout<<"These are id's of the employees in the company"<<endl;
    for(int i=0;i<no_of_employee;i++)
    {
        cout<<"Employee["<<i+1<<"]:";
        e[i].id_display();
    }

    cout<<"To retrive the the details of the employees"<<endl<<"Enter an employee id:";
    cin>>*employee_id;
    
    if(*employee_id<1000)
    {
        cout<<endl<<"****************************************"<<endl<<endl<<"ERROR:ENTERED EMPLOYEE ID DOES NOT EXIST"<<endl<<endl<<"****************************************"<<endl;
        exit(0);
    }
    cout<<endl<<"----------------------------------------"<<endl<<endl;

    for(int i=0;i<no_of_employee;i++)
    {
        bool temp=e[i].check_employee(*employee_id);
        if(temp==true)
        {
            e[i].putdata();
            break;
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
        employee ::avg_experience_display();
        cout<<"THANK YOU";
        exit(0);
    }
    else
    {
        cout<<"Please enter correct option";
        goto select;
    }
}