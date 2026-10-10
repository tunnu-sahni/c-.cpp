//deque
// #include <iostream>
// #include <deque>
// using namespace std;

// int main()
// {
//     deque<int> numbers;

//     numbers.push_back(20);
//     numbers.push_back(30);

//     numbers.push_front(10);
//     numbers.push_front(5);

//     cout << "Deque: ";

//     for (int n : numbers)
//     {
//         cout << n << " ";
//     }

//     numbers.push_front(3);
//     numbers.push_back(2);

//     cout << "\nAfter deletion: ";

//     for (int n : numbers)
//     {
//         cout << n << " ";
//     }

//     return 0;
// }

//stack

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    //push elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    //remove
    s.pop();

    cout << "After pop: " << s.top() << endl;

    cout << "Stack Size: " << s.size() << endl;

    return 0;
}