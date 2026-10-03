// //division by zero
// #include <iostream>
// using namespace std;

// int main()
// {
//     int a = 10;
//     int b = 0;

//     try
//     {
//         if (b ==0)
//         {
//             throw "Division by zero is not allowed";
//         }

//         cout << a / b;
//     }
//     catch (const char* message)
//     {
//         cout << "Error: " << message;

//         return 0;
//     }
// };
//multiple exception handling
// #include <iostream>
// using namespace std;

// int main()
// {
//     int choice;

//     cout << "Enter 1 for integer exception: ";
//     cin >> choice;

//     try
//     {
//         if (choice == 1)
//         {
//             throw 100;
//         }
//         else
//         {
//             throw "Unknown error";
//         }
//     }
//     catch (int error)
//     {
//         cout << "Integer exception: " << error;
//     }
//     catch (const char* error)
//     {
//         cout << "String exception: " << error;
//     }
//     return 0;
// }

//standard exception
// #include <iostream>
// #include <stdexcept>
// using namespace std;

// int main()
// {
//     int age = 15;

//     try
//     {

//         if (age < 18)
//         {
//             throw invalid_argument("Age must be 18 or above");
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return 0;
// }
//template
#include <iostream>
using namespace std;

template <typename T> T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << maximum( 10, 20) << endl;

    cout << maximum(10.5, 5.5) << endl;

    return 0;
}