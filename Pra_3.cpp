// 23cs080, rabadiya kevin

#include<iostream>
#include<string>
using namespace std;

class tata{
    private:
    int seating;
    string model,airbag,trans,fuel;
    float price,mileage,tank;


    public:

    void get_data()
    {
        cout<<"Enter the name of the model:";
        cin>>model;

        cout<<"Fuel type:";
        cin>>fuel;

        cout<<"Enter the price of the car in lakhs:";
        cin>>price;

        cout<<"Enter the mileage:";
        cin>>mileage;

        cout<<"Transmission:";
        cin>>trans;

        cout<<"Enter tank capacity in litres:";
        cin>>tank;

        cout<<"Enter the seating in the car:";
        cin>>seating;

        cout<<"Does it have airbag:";
        cin>>airbag;

    }

    void display_data()
    {
        cout<<"Model:"<<model<<endl;
        cout<<"Fuel type:"<<fuel<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Mileage:"<<mileage<<endl;
        cout<<"Transmission:"<<trans<<endl;
        cout<<"Tank Capacity:"<<tank<<endl;
        cout<<"Seating Capacity:"<<seating<<endl;
        cout<<"Airbag:"<<airbag<<endl;
    }
    void car_name()
    {
        cout<<model<<endl;
    }
    void check_fuel(int n)
    {
        if(n==1 && fuel=="Petrol")
        {
            display_data();
        }
        if(n==2 && fuel=="Diesel")
        {
            display_data();
        }
        if(n==3 && fuel=="CNG")
        {
            display_data();
        }
        if(n==4 && fuel=="Electric")
        {
            display_data();
        }
    }
    void check_price(int n)
    {
        if(n>=price)
        {
            display_data();
        }
        else
        {
            return;
        }
    }

};
int repeat()
{
    string a;
    repeat:
    cout<<endl<<"Do you want to check for any other category(Yes or No):";
    cin>>a;
    if(a=="Yes")
    return 1;
    else if(a=="No")
    return 0;
    else
    goto repeat;
}

int main()
{
    int no_of_car;
    cout<<"What is the number of cars:";
    cin>>no_of_car;
    if(no_of_car<1)
    {
        cout<<"Please enter a correct value"<<endl;
        main();
    }
    tata t[no_of_car];


    for(int i=0;i<no_of_car;i++)
    {
        cout<<"******************************************************"<<endl<<"Enter the details of the car "<<i+1<<endl<<endl;
        t[i].get_data();
    }

    int choice;
    again:
    cout<<"WELCOME TO TATA MOTORS"<<endl<<"GET THE CAR DETAILS AS PER YOUR PREFERENCE"<<endl<<"(1)Model name"<<endl<<"(2)Fuel types"<<endl<<"(3)Price Range"<<endl<<"Enter your option:";
    cin>>choice;
    cout<<"........................................"<<endl;



    switch (choice)
    {
        case 1:
        {
            cout<<"LIST OF TATA CARS"<<endl;
            for(int i=0;i<no_of_car;i++)
            {
                cout << "("<< i+1 <<")";
                t[i].car_name();
            }

            int choice_car;
            cout<<"CHOOSE YOUR CAR TO GET DETAILS:";
            cin>>choice_car;

            if(choice_car>no_of_car)
            {
                cout<<"Please select from the number of cars given to you"<<endl;
                goto again;
            }

            cout<<endl<<endl;
            t[choice_car-1].display_data();

            int again=repeat();

            if(again==1)
            goto again;

            break;
        }

        case 2:
        {
            int preference;
            fuel:
            cout<<"TATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS"<<endl<<"(1)Petrol"<<endl<<"(2)Diesel"<<endl<<"(3)CNG"<<endl<<"(4)Electric"<<endl<<"ENTER YOUR PREFERENCE:";
            cin>>preference;
            if(preference<1 || preference>4)
            {
                cout<<"Please select a valid value";
                goto fuel;
            }
            for(int i=0;i<no_of_car;i++)
            {
                t[i].check_fuel(preference);
                cout<<endl;
            }

            int again=repeat();

            if(again==1)
            goto again;

            break;
        }
        case 3:
        {
            int range;
            cout<<"ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS:";
            cin>>range;

            for(int i=0;i<no_of_car;i++)
            {
                t[i].check_price(range);
                cout<<endl;
            }

            int again=repeat();

            if(again==1)
            goto again;

            break;
        }
        default:
        {
            cout<<"Invalid value"<<endl;
            goto again;
        }
    }
}
