#include <iostream>
using namespace std;

class employee
{
private:
    int empid;
    float sal;

public:
    employee()
    {
        this->empid = 0;
        this->sal = 0;
    }

    employee(int empid, float sal)
    {
        this->empid = empid;
        this->sal = sal;
    }

    int get_id()
    {
        return this->empid;
    }

    float get_sal()
    {
        return this->sal;
    }

    void set_id(int empid)
    {
        this->empid = empid;
    }

    void set_sal(float sal)
    {
        this->sal = sal;
    }

    void accept()
    {
        cout << "Enter EmpID = ";
        cin >> this->empid;
        cout << "Enter Salary = ";
        cin >> this->sal;
    }

    void display()
    {
        cout << "EmpID = " << this->empid << endl;
        cout << "Salary = " << this->sal << endl;
    }
};

class manager : virtual public employee
{
private:
    float bonus;

public:
    manager()
    {
        this->bonus = 0;
    }

    manager(float bonus, int empid, float sal)
    {
        this->bonus = bonus;
        employee::set_id(empid);
        employee::set_sal(sal);
    }

    float get_bonus()
    {
        return this->bonus;
    }

    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        employee::accept();
        cout << "Enter Bonus = ";
        cin >> this->bonus;
    }
    void display()
    {
        employee::display();
        cout << "Bonus = " << this->bonus << endl;
    }

protected:
    void accept_manager()
    {
        cout << "Enter Emp Bonus = ";
        cin >> this->bonus;
    }

    void display_manager()
    {
        cout << "Bonus is = " << this->bonus << endl;
    }
};

class salesman : virtual public employee
{
private:
    float comm;

public:
    salesman()
    {
        this->comm = 0;
    }

    salesman(float comm, int empid, float sal)
    {
        this->comm = comm;
        employee::set_id(empid);
        employee::set_sal(sal);
    }

    float get_comm()
    {
        return this->comm;
    }

    void set_comm(float comm)
    {
        this->comm = comm;
    }

    void accept()
    {
        employee::accept();
        cout << "Enter Commission = ";
        cin >> this->comm;
    }

    void display()
    {
        employee::display();
        cout << "Commission = " << this->comm << endl;
    }

protected:
    void accept_salesman()
    {
        cout << "Enter Commission = ";
        cin >> this->comm;
    }

    void display_salesman()
    {
        cout << "Commission offered = " << this->comm << endl;
    }
};

class sales_manager : public manager, public salesman
{
public:
    sales_manager()
    {
    }

    sales_manager(int empid, float sal, float bonus, float comm)
    {
        employee::set_id(empid);
        employee::set_sal(sal);
        manager::set_bonus(bonus);
        salesman::set_comm(comm);
    }

    void accept()
    {
        employee::accept();
        // manager::accept();
        manager::accept_manager();
        // salesman::accept();
        salesman::accept_salesman();
    }

    void display()
    {
        cout << "**************************************************" << endl;
        employee::display();
        // manager::display();
        manager::display_manager();
        // salesman::display();
        salesman::display_salesman();
    }
};
int main()
{
    // sales_manager sm1;
    //  sm1.accept();
    // sm1.display();

    employee e;
    manager m;
    salesman s;
    sales_manager sm;

    cout << "Enter the Information of Employee" << endl;
    cout << "********************************************" << endl;
    e.accept();
    cout << "----------------------------------------------" << endl;
    e.display();

    cout << "Enter the Information of Manaager" << endl;
    cout << "********************************************" << endl;
    m.accept();
    cout << "----------------------------------------------" << endl;
    m.display();

    cout << "Enter the Information of Sales-Man " << endl;
    cout << "********************************************" << endl;
    s.accept();
    cout << "----------------------------------------------" << endl;
    s.display();

    cout << "Enter the Information of Sales-Manager" << endl;
    cout << "********************************************" << endl;
    sm.accept();
    cout << "----------------------------------------------" << endl;
    sm.display();

    return 0;
}