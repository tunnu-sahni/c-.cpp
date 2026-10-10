// //copy and move

// #include <iostream>
// #include <vector>
// #include <utility>
// using namespace std;

// int main()
// {
//     vector<int> a = {10, 20, 30};

//     vector<int> b = a;

//     cout << "Original vector: ";

//     for (int x : a)
//         cout << x << " ";

//     cout << "\ncopied vector: ";

//     for (int x : b)
//         cout << x << " ";

//     vector<int> c = move(a);

//     cout << "\nmoved vector: ";

//     for (int x : c)
//         cout << x << " ";

//     cout << "\nOriginal vector size after move: " << a.size();

//     return 0;
// }

//rvalue reference

// #include <iostream>
// using namespace std;

// int main()
// {
//     int x = 10;

//     int& lref = x;

//     int&& rref = 100;

//     cout << "Lvalue Reference: " << lref << endl;

//     cout << "Rvalue Reference: " << rref << endl;

//     return 0;
// }

//move constructor

// #include <iostream>
// #include <utility>
// using namespace std;

// class Box
// {
// private:
//     int* data;

// public:

//     Box(int value)
//     {
//         data = new int(value);

//         cout << "Constructor called " << endl;
//     }
//     //move constructor
//     Box(Box&& other) noexcept
//     {
//         data = other.data;

//         other.data = nullptr;

//         cout << "Move constructor called" << endl;
//     }

//     void display()
//     {
//         if (data != nullptr)
//         {
//            cout << "Value: " << *data << endl;
//         }
//         else
//         {
//             cout << "No data" << endl;
//         }
//     }
//     ~Box()
//     {
//         delete data;

//         cout << "Destructor called" << endl;
//     }
// };

// int main()
// {
//     Box b1(100);

//     Box b2 = move(b1);

//     cout << "B1: ";
//     b1.display();

//     cout << "B2: ";
//     b2.display();

//     return 0;
// }

//move assignment operator

#include <iostream>
#include <utility>
using namespace std;

class Box
{
private:
    int* data;

public:
    
    Box(int value)
    {
        data = new int(value);

        cout << "Constructor called " << endl;
    }

    //move assignment operator
    Box& operator=(Box&& other) noexcept
    {
        if (this != &other)
        {
            delete data;

            data = other.data;

            other.data = nullptr
        }

        cout << "Move assignment called " << endl;

        return *this;
    }

    void display()
    {
        if (data != nullptr)
        cout << *data << endl;

        else
            cout << "No data" << endl;
    }
    ~Box()
    {
        delete data;
    }
};

int main()
{
    Box b1(100);

    Box b2(200)

    b2 = move(b1);

    cout << "B1: ";
    b1.display();

    cout << "B2: ";
    b2.display();

    return 0;
}