// //implicit type casting
// #include <iostream>
// using namespace std;

// int main()
// {
//     int number = 10;

//     double result = number;

//     cout << "implicit type casting: " << result << endl;
//     return 0;
// }
//c-style casting
// #include <iostream>
// using namespace std;

// int main()
// {
//     double price = 99.99;

//     int value = (int)price;

//     cout << "c-style casting: " << value << endl;

//     return 0;
// }
//static_cast

// #include <iostream>
// using namespace std;

// int main()
// {
//     double price = 99.99;

//     int value = static_cast<int>(price);

//     cout << value;

//     return 0;
// }

//ingeter percentage display
// #include <iostream>
// using namespace std;

// int main()
// {
//     double marks = 85.75;

//     int percentage = static_cast<int>(marks);

//     cout << "Percentage:" << percentage << "%";

//     return 0;
// }
//const cast
#include <iostream>
using namespace std;

void display(const int*ptr)
{
    int* p = const_cast<int*>(ptr);

    cout << *p;
}
int main()
{
    int number = 100;

    display(&number);

    return 0;
}
//reinterpret_cast
#include <iostream>
using namespace std;

int main()
{
    int number = 100;

    int*ptr = &number;

    cout << "value: " << *ptr << endl;

    return 0;
}