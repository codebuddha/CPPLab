#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    std::string a, b="";
    getline(cin, a);
    stringstream c(a);

    while(c >> a)
    {
        reverse(a.begin(), a.end());
        b += a + string(" ");
    }
    cout << b << "\n";
    return 0;
}
