// a map is an associate container that stores element as key-value pairs, with unique keys sorted by key
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     map<string, int> marks;

//     marks["Tunnu"] = 90;
//     marks["Rahul"] = 85;
//     marks["Aman"] = 78;

//     cout << "sahni marks: " << marks["sahni"] << endl;

//     cout << "\nAll students:\n";

//     for (auto item : marks)
//     {
//         cout << item.first << " : " << item.second << endl;
//     }

//     return 0;
// }

//unorderes containers store element using hash tables rather than maintaining sorted order

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main()
// {
//     unordered_set<int> numbers;

//     numbers.insert(10);
//     numbers.insert(20);
//     numbers.insert(30);
//     numbers.insert(10);

//     cout << "Element: ";

//     for (int n : numbers)
//     {
//         cout << n << " ";
//     }

//     cout << "\nSize: " << numbers.size();

//     return 0;
// }

// unordered map
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> students;

    students["sahni"] = 90;
    students["Rahul"] = 85;
    students["Aman"] = 68;

    cout << "sahni marks: " << students["sahni"] << endl;

    cout << "\nAll records:\n";

    for (auto item : students)
    {
        cout << item.first << " : " << item.second << endl;
    }

    return 0;
}