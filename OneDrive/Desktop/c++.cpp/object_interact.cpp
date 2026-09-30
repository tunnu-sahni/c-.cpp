// //two objects interacting
// #include <iostream>
// using namespace std;

// class Calculator
// {
//     public:

//     int add(int a, int b)
//     {
//         return a + b;
//     }
// };

// class Student
// {
//     public:

//        void claculateMarks(Calculator &calc)
//        {
//         int result = calc.add(40, 50);

//         cout << "Total Marks: " << result << endl;
//        }
// };

// int main()
// {
//     Calculator Calculator;
//     Student student;

//     student.claculateMarks(Calculator);

//     return 0;
// }

//encapsulation

// #include <iostream>
// using namespace std;

// class BankAccount
// {
//     private:
//     double balance;

//     public:

//     void deposit(double amount)
//     {
//         if (amount > 0)
//         {
//             balance += amount
//         }
//     }

//     void withdraw(double amount)
//     {
//         if (amount > 0 && amount <= balance)
//         {
//             balance -= amount;
//         }
//         else
//         {
//             cout << "Invalid withdraw" << endl;
//         }
//     }

//     double getBalance()
//     {
//         return balance;
//     }
// };

// int main()
// {
//     BankAccount account;

//     account.deposit(10000);
//     account.withdraw(3000);

//     cout << "Balance: " << account.getBalance() << endl;

//     return 0;
// }