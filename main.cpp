//
//  main.cpp
//  Assignment3
//
//  Created by kareem ahmed shawky on 3/14/23.
//  Karim Shawky 900221948

#include <iostream>
#include "Class.h"
using namespace std;

int main()
{
    string Name, ID;
    int count = 0;
    customer CustomerInfo;
    mechanic MechanicInfo;
    queue<string> MecList;
    queue<string> CustomerList;
    cout << "Enter mechanic name (Enter 0 when all mechanics have been entered)\n";
    do
    {
        cout << "Mechanic Name: ";
        cin >> Name;
        if (Name == "0")
        {
            break;
        }
        else
        {
            MecList.Push(Name);
            count++;
        }
    }while(Name != "0");
    
    cout << "Current Mechanics in list: \n";
    for(int i = 0; i < count; i++)
    {
        cout << MecList.Pop() << endl;
    }
    
    cout << "Enter customer name and appointment time (hh mm) (enter 0 at name when all appointments have been entered) \n";
    int h, m, CustomerCount = 0;
    do
    {
        cout << "Customer Name: ";
        cin >> Name;
        cout << endl;
        if (Name == "0")
        {
            break;
        }
        CustomerList.Push(Name);
        CustomerList.Push("at");
        cout << "Time: ";
        cin >> h >> m;
        cout << endl;
        CustomerInfo.SetAppointment(h, m);
        for (int i = 0; i < count; i++)
        {
            if(CustomerInfo.GetAppointmentHour() != MechanicInfo.GetHour(i))
            {
                MechanicInfo.SetAppointment(h, m);
                CustomerList.Push(CustomerInfo.time);
            }
            else
            {
                cout << "This Appointment is already occupied";
            }
        }
        
        CustomerCount++;
    }while(CustomerCount != count);
    
    cout << "Current customers in line: \n";
    for(int i = 0; i < CustomerCount*3; i++)
    {
        cout << CustomerList.Pop() << " ";
        if(i % 3 == 2)
        {
            cout << endl;
        }
    }
    
    return 0;
}

