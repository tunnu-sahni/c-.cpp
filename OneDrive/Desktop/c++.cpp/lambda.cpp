// //lambda expression
// #include <iostream>
// using namespace std;

// int main()
// {
//     auto add = [](int a, int b)
//     {
//         return a + b;
//     };

//     int result = add(10, 20);
//     cout << "Sum: " << result;

//     return 0;
// }

//lambda with capture
// #include <iostream>
// using namespace std;

// int main()
// {
//     int bonus = 10;

//     auto calculate = [bonus](int marks)
//     {
//         return marks + bonus;
//     };
//     cout << calculate(80);

//     return 0;
// }

//transform bonus marks add
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> marks = {60, 70, 80, 90 , 100};

    int bonus = 5;

    transform(marks.begin(), marks.end(), marks.begin(), [bonus](int m)
    {
        return m + bonus;
    });

    for (int mark : marks)
    {
        cout << mark << " ";
    }

    return 0;
}