#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {1, 2, 3};
    cout << "Trying ccls!" << std::endl;
    cout << "Hello world!" << endl;
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}