// //reading from file
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     ifstream file("student.txt");

//     string line;

//     if (file.is_open())
//     {
//         while (getline(file, line))
//         {
//             cout << line << endl;
//         }

//         file.close();
//     }
//     else{
//         cout << "file not found";
//     }
//     return 0;
// }
//fstream

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file("data.txt, ios::in | ios::app");

    if (file.is_open())
    {
        file << "hello c++\n";

        file.close();

        cout << "data added";
    }
    return 0;
}