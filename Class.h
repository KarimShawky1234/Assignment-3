//
//  Class.h
//  Assignment3
//
//  Created by kareem ahmed shawky on 3/14/23.
//
//  Karim Shawky 900221948


#ifndef Class_h
#define Class_h
using namespace std;

class Person
{
public:
    Person()
    {
        Name = " ";
        ID = " ";
        Age = 0;
    }
private:
    string Name;
    string ID;
    int Age;
    
    
public:
    
    void SetName(string name)
    {
        Name = name;
    }
    
    string GetName()
    {
        return Name;
    }
    
    void SetID(string id)
    {
        ID = id;
    }
    
    string GetID()
    {
        return ID;
    }
    
    void SetAge(int age)
    {
        Age = age;
    }
    
    int GetAge()
    {
        return Age;
    }
    
    void printinfo()
    {
        cout << "Name: " << Name << endl;
        cout << "ID: " << ID << endl;
        cout << "Age: " << Age << endl;
    }
 
protected:
    
    struct Appointment
    {
        int hours;
        int minutes;
    };
    
};

class customer: public Person
{
public:
    customer()
    {
        MechanicID = " ";
        appointment.hours = 0;
        appointment.minutes = 0;
    }
private:
    
    string MechanicID;
    Appointment appointment;
    
public:
    
    string time;
    void SetMechID(string ID)
    {
        MechanicID = ID;
    }
    
    string GetMechID()
    {
        return MechanicID;
    }
    
    void SetAppointment(int h, int m)
    {
        appointment.hours = h;
        appointment.minutes = m;
        time = to_string(appointment.hours) + ":" + to_string(appointment.minutes);
    }

    int GetAppointmentHour()
    {
        return appointment.hours;
    }
    
    int GetAppointmentMinutes()
    {
        return appointment.minutes;
    }
    
    bool operator> (const Appointment& time) const
    {
        if (appointment.hours > time.hours && appointment.minutes > time.minutes)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool operator< (const Appointment& time) const
    {
        if (appointment.hours < time.hours && appointment.minutes < time.minutes)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool operator== (const Appointment& time) const
    {
        if (appointment.hours == time.hours && appointment.minutes == time.minutes)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

class mechanic: public Person
{
    
private:
    
    int counter;
    int size = 10;
    Appointment *Arr= new Appointment[size];
    
public:
    
    mechanic()
    {
        counter = 0;
        for (int i = 0; i < size; i++)
        {
            Arr[i].hours = 0;
            Arr[i].minutes = 0;
        }
    }
    
    bool isAvailable(Appointment time)
    {
        bool Availability = true;
        for(int i = 0; i < counter; i++)
        {
            if (time.hours == Arr[i].hours && time.minutes == Arr[i].minutes)
            {
                Availability = false;
            }
        }
        return Availability;
    }
    
    void SetCounter(int num)
    {
        counter = num;
    }
    
    int GetCounter()
    {
        return counter;
    }
    
    void SetAppointment(int h, int m)
    {
        for(int i = 0; i < counter; i++)
        {
            if (Arr[i].hours == 0 && Arr[i].minutes == 0)
            {
                Arr[i].hours = h;
                Arr[i].minutes = m;
            }
        }
    }
    
    int GetHour(int i)
    {
        return Arr[i].hours;
    }
    
    int GetMinutes(int i)
    {
        return Arr[i].minutes;
    }
    
};

template <class T> class queue
{
    T *Arr;
    int capacity, front, rear, count;
    
public:
    queue(int size = 10)
    {
        Arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    bool IsEmpty()
    {
        if (count)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    bool IsFull()
    {
        if (count < capacity)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    void Push(T item)
    {
        if(IsFull())
        {
            cout << "Error: queue is full";
        }
        else
        {
            rear = (rear + 1) % capacity;
            Arr[rear] = item;
            count++;
        }
    }
    
    T Pop()
    {
        T item;
        if(IsEmpty())
        {
            cout << "Error: Queue if empty";
            return " ";
        }
        else
        {
            item = Arr[front];
            front = (front + 1) % capacity;
            count--;
            return item;
        }
    }
    
    void DisplayQueue()
    {
        cout << "front -->";
        for (int i = 0; i < count; i++)
        {
            if (i == 0)
            {
                cout << "\t";
            }
            else
            {
                cout << "\t\t";
                cout << Arr[(front + i) % capacity];
            }
            
            if (i != count - 1)
            {
                cout << endl;
            }
            else
            {
                cout << "\t<-- rear" << endl;
            }
        }
    }
};

#endif /* Class_h */
