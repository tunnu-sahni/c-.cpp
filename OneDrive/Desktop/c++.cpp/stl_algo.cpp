// //sort
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> number = {50, 10, 40, 20, 30};

//     sort(number.begin(), number.end());

//     for (int n: number)
//     {
//         cout << n << " ";
//     }
//     return 0;
// }

// //reverse

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> number = {10, 20, 30, 40};

//     reverse(number.begin(), number.end());

//     for (int n: number)
//     {
//         cout << n << " ";
//     }
//     return 0;
// }
//find

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> number = {10, 20, 30, 40};

//     auto it = find(number.begin(), number.end(), 30);

//     if(it != number.end())
//     {
//         cout << "Element found";

//     }
//     else
//     {
//         cout << "Element not found";
//     }
//     return 0;
// }

//count

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> number = {10, 20, 10, 30, 10 };

//     int result = count(number.begin(), number.end(), 10);

//     cout << "10 occurs " << result << " times ";

//     return 0;
// }
// maximum and minimum 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> marks = {76, 34, 54, 23};

    auto maximum = max_element(marks.begin(), marks.end());

    auto minimum = min_element(marks.begin(), marks.end());

    cout << "Maximum: " << *maximum << endl;
    cout << "Minimum: " <<*minimum << endl;

    return 0;
}
