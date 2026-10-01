// #include <iostream>
// using namespace std;

// class Person
// {
//     public:

//     string name;

//     void eat()
//     {
//         cout << name << " is eating" << endl;
//     }
// };

// class Student : public Person
// {
//     public:

//     void study()
//     {
//         cout << name << " is stuying" << endl;
//     }
// };

// int main()
// {
//     Student s;

//     s.name = "Sahni";

//     s.eat();
//     s.study();

//     return 0;
// }
//one base one derived
// #include <iostream>
// using namespace std;

// class Animal
// {
//     public:

//        void eat()
//        {
//         cout << "Animal is eating" << endl;
//        }
// };
// class Dog : public Animal
// {
//     public:

//        void bark()
//        {
//         cout << "Dog is barking" << endl;
//        }
// };

// int main()
// {
//     Dog d;

//     d.bark();
//     d.bark();

//     return 0;
// }
//multiple inheritance
#include <iostream>
using namespace std;

class Animal
{
    public:

       void eat()
       {
        cout << "Animal is eating " << endl;
       }
};
class Mammal : public Animal
{
    public:

       void walk()
       {
        cout << "Mammal walks" << endl;
       }
};

class Dog : public Mammal
{
    public:

       void bark()
       {
        cout << "dog barks" << endl;
       }
};

int main()
{
    Dog d;

    d.eat();
    d.walk();
    d.bark();

    return 0;
}