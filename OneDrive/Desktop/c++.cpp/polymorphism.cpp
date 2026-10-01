// //function overriding
// #include <iostream>
// using namespace std;

// class Animal
// {
//     public:
      
//        void sound()
//        {
//         cout << "Animal makes sound" << endl;
//        }
// };

// class Dog : public Animal
// {
//     public:

//        void sound()
//        {
//         cout << "Dog barks" << endl;
//        }
// };

// int main()
// {
//     Dog d;

//     d.sound();

//     return 0;
// }

//runtime polymorphism with virtual
#include <iostream>
using namespace std;

class Animal
{
    public:

       virtual void sound()
       {
        cout << "Animal makes a sound" << endl;
       }
};

class Dog : public Animal
{
    public:

       void sound() override
       {
        cout << "Dog barks" << endl;
       }
};

class Cat : public Animal
{
    public:

       void sound() override
       {
        cout << "Cat meows" << endl;
       }
};

int main()
{
    Animal* animal;

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    return 0;
}