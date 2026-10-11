// //queue
// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {
//     queue<int> q;

//     q.push(10);
//     q.push(20);
//     q.push(30);

//     cout << "Front: " << q.front() << endl;

//     cout << "Back: " << q.back() << endl;

//     q.pop();

//     cout << "Size: " << q.size() << endl;

//     return 0;
// }

//set

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> numbers;

    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);
    numbers.insert(40);

    cout << "Set Element: ";

    for (int n : numbers)
    {
        cout << n << " ";
    }

    cout << "\nTotal Element: " << numbers.size();

    if (numbers.find(20) != numbers.end())
    {
        cout << "\n20 Found";
    }

    numbers.erase(30);

    cout << "\nAfter deletion: ";

    for (int n : numbers)
    {
        cout << n << " ";
    }

    return 0;
}