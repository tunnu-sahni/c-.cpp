// for loop
// #include <iostream>
// using namespace std;

// int main() {
//     for (int i = 1; i <= 5; i++)
//     {
//         cout << "Student " << i << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     for (int i = 1; i <= 5; i++)
//     {
//         cout << "Student  " << i << endl;
//     }
//     return 0;
// }

// while loop
// #include <iostream>
// using namespace std;

// int main() {
//     int battery = 50;

//     while (battery > 20)
//     {
//         cout << "phone is running. battery: "
//         << battery << "%" << endl;

//         battery -= 10;
//     }
//     cout << "battery is low.";

//     return 0;
// }

//do-while loop
// #include <iostream>
// using namespace std;

// int main() {
//     int choice;

//     do
//     {
//         cout << "\nATM MENU\n";
//         cout << "1. Balance\n";
//         cout << "2. Withdraw\n";
//         cout << "3. Exit\n";

//         cout << "enter choice: ";
//         cin >> choice;
//     } while (choice != 3);

//     cout << "Thank you for using ATM.";

//     return 0;
// }

//break
// #include <iostream>
// using namespace std;

// int main(){
//     for (int i = 1; i <= 10; i++)
//     {
//         cout << i << endl;
//         if (i == 6)
//         {
//             break;
//         }
//     }
//     return 0;
// }

// continue

#include <iostream>
using namespace std;

int main() {
    for (int i =1; i <= 10; i++)
    {
        if (i == 5)
        {
            continue;
        }
        cout << i << endl;
    }

    return 0;
}
