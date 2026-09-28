//if statement
// #include <iostream>
// using namespace std;

// int main() {
//     int balance = 1000;
//     int withdraw = 500;

//     if (withdraw <= balance) {
//         cout << "withdraw successful";
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;

// int main() {
//     int balance = 500;
//     int cash_withdraw = 100;
//     if (cash_withdraw <= balance) {
//         cout << "cash_withdraw successful";
//     }
//     return 0;
// }

// if-else statement

// #include <iostream>
// using namespace std;

// int main() {
//     string password;

//     cout << "enter password: ";
//     cin >> password;

//     if (password == "1234") 
//     {
//         cout << "login successful";
//     }
//     else
//     {
//         cout << "invalid password";
//     }
//     return 0;
// }

//else-if statement
// #include <iostream>
// using namespace std;

// int main() {
//     int marks;
//     cout << "enter your marks: ";
//     cin >> marks;

//     if (marks >= 90)
//     {
//         cout << "Grade A";
//     }
//     else if (marks >= 80)
//     {
//         cout << "Grade B";
//     }
//     else if (marks >= 70)
//     {
//         cout << "Grade C";
//     }
//     else if (marks >= 60)
//     {
//         cout << "Grade D";
//     }
//     else if (marks >= 50)
//     {
//         cout << "Grade F";
//     }
//         return 0;
// }

// nested if statement
// #include <iostream>
// using namespace std;

// int main() {
//     int age;
//     int income;
//     cout << "enter your age: ";
//     cin >> age;
//     cout << "enter your income: ";
//     cin >> income;

//     if (age >= 18)
//     {
//         if (income >= 25000)
//         {
//             cout << "loan eligible";
//         }
//         else
//         {
//             cout << "income is too low";
//         }
//     }
//     else
//     {
//         cout << "age is too low";
//     }
//     return 0;
// }

// switch statement
// #include <iostream>
// using namespace std;

// int main() {
//     int choice;

//     cout << "ATM MENU\n";
//     cout << "1. Check Balance\n";
//     cout << "2. Withdraw Money\n";
//     cout << "3. Deposit Money\n";
//     cout << "4. Exit\n";

//     cout << "enter your choice: ";
//     cin >> choice;

//     switch (choice)
//     {
//         case 1:
//         cout << "Checking balance...";
//         break;

//         case 2:
//         cout << "Withdraw Money";
//         break;

//         case 3:
//         cout << "Deposit Money";
//         break;

//         case 4:
//         cout << "Thank you";
//         break;

//         default:
//         cout << "invalid choice";
//     }
//     return 0;
// }
