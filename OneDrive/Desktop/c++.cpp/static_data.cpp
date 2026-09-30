// //static data member
// #include <iostream>
// using namespace std;

// class Student
// {
//     public:
//     string name;

//     static int count;

//     Student(string n)
//     {
//         name = n;
//         count++;
//     }

//     void display()
//     {
//         cout << "Student: " << name << endl;
//     }
// };
// int Student::count = 0;

// int main()
// {
//     Student s1("sahni");
//     Student s2("tunnu");
//     Student s3("adarsh");

//     s1.display();
//     s2.display();
//     s3.display();

//     cout << "Total Students: " << Student::count << endl;

//     return 0;
// }

//static member dunction
#include <iostream>
using namespace std;

class Student
{
private:
    static int count;

public:
    Student()
    {
        count++;
    }
    static void showCount()
    {
        cout << "Total objects: " << count << endl;
    }
};
int Student::count = 0;

int main()
{
    Student s1;
    Student s2;
    Student s3;

    Student::showCount();

    return 0;
}