// //auto keyword

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     auto age = 21;
//     auto price = 99.90
//     auto name = string("tunnu");
//     auto marks = 90.8f;

//     cout << "Age: " << age << endl;
//     cout << "Price: " << price << endl;
//     cout << "Name: " << name << endl;
//     cout << "Marks: " << marks << endl;

//     return 0;
// }

// range based for loop
// #include <iostream>
// using namespace std;

// int main()
// {
//     int numbers[] = {10, 20, 30, 40, 50};

//     cout << "Array Elements:" << endl;

//     for (int number : numbers)
//     {
//         cout << number << endl;
//     }
//     return 0;
// }

//reference loop
// #include <iostream>

// int main()
// {
//     int numbers[] = {10, 20, 30, 40, 50};

//     for (int &number : numbers)
//     {
//         number = number + 5;
//     }

//     for (int number : numbers)
//     {
//         cout << number << " ";
//     }
//     return 0;
// }