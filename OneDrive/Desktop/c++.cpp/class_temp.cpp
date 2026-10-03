#include <iostream>
using namespace std;

template <typename T>
class Box
{
    private:
        T value;

    public:

       Box(T v)
       {
        value = v;
       }
       void display()
       {
        cout << "value: " << value << endl;
       }
};

int main()
{

    Box<double> box2(99.99);

    Box<string> box3("Hello");

    box2.display();
    box3.display();

    return 0;
}