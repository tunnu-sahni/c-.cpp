//mutex

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;

mutex m;

void increase()
{
    for (int i = 0; i < 10000; i++)
    {
        lock_guard<mutex> lock(m);

        counter++;
    }
}

int main()
{
    thread t1(increase);
    thread t2(increase);

    t1.join();
    t2.join();

    cout << "Counter: " << counter;

    return 0;
}