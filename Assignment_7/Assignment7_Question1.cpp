#include <iostream>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int get_day()
    {
        return this->day;
    }

    int get_month()
    {
        return this->month;
    }

    int get_year()
    {
        return this->year;
    }

    void set_day(int day)
    {
        this->day = day;
    }

    void set_month(int month)
    {
        this->month = month;
    }

    void set_year(int year)
    {
        this->year = year;
    }

    void accept()
    {
        cout << "Enter day = ";
        cin >> this->day;
        cout << "Enter month = ";
        cin >> this->month;
        cout << "Enter year = ";
        cin >> this->year;
    }

    void display()
    {
        cout << "Date => " << this->day << " / " << this->month << " / " << this->year << endl;
    }

    bool is_leap_year()
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return true;
        else
            return false;
    }
};

class person
{
private:
    string name;
    string address;
    date birth_date;

public:
    person()
    {
        this->name = "xyz";
        this->address = "xyz";
    }

    person(string name, string address, int day, int month, int year) //: birth_date(day, month, year)
    {
        this->name = name;
        this->address = address;
        birth_date.set_day(day);
        birth_date.set_month(month);
        birth_date.set_year(year);
    }

    string get_name()
    {
        return this->name;
    }

    string get_address()
    {
        return this->address;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    void set_address(string address)
    {
        this->address = address;
    }

    date get_birth_date()
    {
        return this->birth_date;
    }

    void set_birth_date(date birth_date)
    {
        this->birth_date = birth_date;
    }

    void accept()
    {
        cout << "******************************************************" << endl;

        getchar();
        cout << "Enter Name => ";
        // cin >> this->name;
        getline(cin, name);
        cout << "Enter Address => ";
        // cin >> this->address;
        getline(cin, address);
        cout << "Enter Birth Date=> ";
        birth_date.accept();
    }

    void display()
    {
        cout << "******************************************************" << endl;
        cout << "Name => " << this->name << endl;
        cout << "Address => " << this->address << endl;
        cout << "Birth ";
        birth_date.display();
    }
};

class employee : public person
{
private:
    int empid;
    float sal;
    string dept;
    date joining;

public:
    employee()
    {
        this->empid = 0;
        this->sal = 0;
        this->dept = "xyz";
    }

    employee(string name, string address, int empid, float sal, string dept, int day, int month, int year) : joining(day, month, year)
    {
        
        this->set_name(name);
        this->set_address(address);
        this->empid = empid;
        this->sal = sal;
        this->dept = dept;

        // joining.set_day(day);
        // joining.set_month(month);
        // joining.set_year(year);
    }

    int get_id()
    {
        return this->empid;
    }

    float get_sal()
    {
        return this->sal;
    }

    string get_dept()
    {
        return this->dept;
    }

    void set_id(int empid)
    {
        this->empid = empid;
    }

    void set_sal(float sal)
    {
        this->sal = sal;
    }

    void set_dept(string dept)
    {
        this->dept = dept;
    }

    date get_joining_date()
    {
        return this->joining;
    }

    void set_joining_date(date joining)
    {
        this->joining = joining;
    }

    void accept()
    {
        cout << "******************************************************" << endl;

        person::accept();

        cout << "Enter EmpID = ";
        cin >> this->empid;

        cout << "Enter Salary= ";
        cin >> this->sal;

        cout << "Enter Department= ";
        cin >> this->dept;

        cout << "Enter Joining Date = ";
        joining.accept();
    }

    void display()
    {
        cout << "******************************************************" << endl;
        person::display();
        cout << " Empid=> " << this->empid << endl;
        cout << " Salary=> " << this->sal << endl;
        cout << " Department=> " << this->dept << endl;
        cout << " Joining ";
        joining.display();
    }
};
int main()
{
    // person p;
    // p.accept();
    // p.display();

    // person p1("Vinod Patil", "Vishrambagh, Sangli", 8, 5, 1997);
    // p1.display();

    // employee e(01, 10000, "Mechanical", 01, 01, 2023);
    // e1.display();

    employee e1;
    e1.accept();
    e1.display();

    return 0;
}