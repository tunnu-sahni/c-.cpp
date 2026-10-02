#include <iostream>
using namespace std;

class payment
{
    public:
        virtual void pay()
        {
            cout << "payment mode" << endl;
        }
};

class UPI : public payment
{
    public:

         void pay() override
         {
            cout << "payment through UPI" << endl;
         }
};

class Card : public payment
{
    public:

        void pay() override
        {
            cout << "payment through Card" << endl;
        }
};

int main()
{
    payment* payment;

    UPI upi;
    Card card;

    payment = &upi;
    payment->pay();

    payment = &card;
    payment->pay();

    return 0;
}