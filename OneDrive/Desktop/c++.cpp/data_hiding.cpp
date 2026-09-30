#include <iostream>
using namespace std;

class Employee
{
    private:
    double salary;

    public:

    void setSalary(double s)
    {
        if (s >= 0)
        {
            salary = s;
        }
        else
        {
            cout << "Salary cannot be nagative" << endl;
        }
    }

    double getSalary()
    {
        return salary;
    }
};

int main()
{
    Employee e;

    e.setSalary(50000);

    cout << "Salary: " << e.getSalary() << endl;

    return 0;
}