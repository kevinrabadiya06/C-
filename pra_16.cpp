//THIS PROGRAM IS PREPARED BY 23CS080 RABADIYA KEVIN
#include <iomanip>
#include <iostream>
#include <string>
#include<sstream>
#include <fstream>
using namespace std;
class Car {
private:
    string modelName;
    string Ft;
    float price;
    float mileage;
    string transmission;
    float tankCapacity;
    int seating;
    string airbags;
public:
    void inputDetails(ifstream &file)
    {
        getline(file,modelName,',');
        getline(file,Ft,',');
        file >> price;
        file.ignore();
        file >> mileage;
        file.ignore();
        getline(file,transmission,',');
        file >> tankCapacity;
        file.ignore();
        file >> seating;
        file.ignore();
        getline(file,airbags,';');
    }
    void displaydata() {
        cout<<modelName<<setw(5)<<" "<<setw(-15)<<Ft<<setw(5)<<" "<<setw(-15)<< price <<setw(10)<<" "<<setw(-15)<<mileage<<setw(10)<<" "<<setw(-15)<<transmission<<setw(10)<<" "<<setw(-15)<<tankCapacity<<setw(19)<<" "<<setw(-15)<<seating<<setw(15)<<airbags<<endl;
    }
    string getmodelName(){
        return modelName;
    }
    void fueltype(int n)
    {
        if(n==1 && Ft=="Petrol")
        {
            displaydata();
        }
        if(n==2 && Ft=="Diesel")
        {
            displaydata();
        }
        if(n==3 && Ft=="CNG")
        {
            displaydata();
        }
        if(n==4 && Ft=="Electric")
        {
            displaydata();
        }
    }
    void pricerange(int m)
    {
        if(price<=m)
        {
            displaydata();
        }
    }
};
int main() {
    Car car[7];
    int i;
    int option,option2;
    ifstream fin;
    fin.open("cardata.txt");
    for(int i=0;i<7;++i)
    {
        car[i].inputDetails(fin);
    }
    system("CLS");
    again:
    cout << "WELCOME TO TATA MOTORS" << endl;
    cout << "GET THE CAR AS PER YOUR PREFRENCE" << endl;
    cout << "(1) Model Name (2) Fuel type (3) Price range"<< endl;
    cout << "ENTER YOUR OPTION : ";
    cin >> option;
    cout << "-----------------------------"<< endl;
    fflush(stdin);
    switch (option)
    {
        case 1:
        {
            cout << "LIST OF TATA CARS" << endl;
            for(i=0;i<7;i++)
            {
                cout << "(" << i+1 << ") " << car[i].getmodelName() << "\t" ;
            }
            cout << endl << "CHOOSE YOUR CAR TO GET DETAILS : ";
            cin >> option2;
            option2=option2-1;
            cout<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(15)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(15)<<"Seating"<<setw(15)<<"Airbags"<<endl;
            cout<<setw(20)<<" "<<"(Lakhs)"<<setw(10)<<"km/L"<<setw(20)<<" "<<"(Liters)"<<setw(21)<<"Capacity"<<endl;
            car[option2].displaydata();
        }
            goto again;
            break;
        case 2:
        {
            cout<<"TATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS"<<endl<<"(1) Petrol (2) Diesel (3) CNG (4) Electric " << endl;
            cout<<"ENTER YOUR FUEL PREFRENCE : ";
            int choice;
            cin>>choice;
            cout<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(15)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(15)<<"Seating"<<setw(15)<<"Airbags"<<endl;
            cout<<setw(20)<<" "<<"(Lakhs)"<<setw(10)<<"km/L"<<setw(20)<<" "<<"(Liters)"<<setw(21)<<"Capacity"<<endl;
            for(int i=0; i<7; i++)
            {
            car[i].fueltype(choice);
            cout<<endl;
            }
            goto again;
            break;
        }
        case 3:
        {
            float range;
            cout << "ENTER YOUR MAXIMUM AFFORDABLE PRICE RANGE IN LAKHS : ";
            cin >> range;
            cout<<"Model"<<setw(10)<<"Fuel"<<setw(10)<<"Price"<<setw(15)<<"Mileage"<<setw(15)<<"Transmission"<<setw(15)<<"Tank Capacity"<<setw(15)<<"Seating"<<setw(15)<<"Airbags"<<endl;
            cout<<setw(20)<<" "<<"(Lakhs)"<<setw(10)<<"km/L"<<setw(20)<<" "<<"(Liters)"<<setw(21)<<"Capacity"<<endl;
            for(int i=0; i<7; i++)
            {
            car[i].pricerange(range);
            cout<<endl;
            }
            goto again;
            break;
        }
        default:
            cout << "Invalid option!" << endl;
            exit(0);
    }
    return 0;
}
