// //vector
// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     vector<int> numbers;

//     //adding elements

//     numbers.push_back(10);
//     numbers.push_back(20);
//     numbers.push_back(30);
//     numbers.push_back(40);

//     cout << "vector Elements: ";

//     for (int n : numbers)
//     {
//         cout << n << " ";
//     }

//     //access element
//     cout << "\nFirst Element: " << numbers[0];

//     //remove last element
//     numbers.pop_back();

//     cout << "\nAfter pop_back: ";

//     for (int n : numbers)
//     {
//         cout << n << " ";
//     }

//     cout << "\nSize: " << numbers.size();
    
//     return 0;
// }

//list

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    numbers.push_front(5);

    cout << "List: ";

    for (int n : numbers)
    {
        cout << "\nAfter pop>front: ";

        for (int n : numbers)
        {
            cout << n << " ";
        }
    }
    return 0;
}