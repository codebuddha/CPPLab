#include <iostream>
#include <vector>
using namespace std;
int binary_search(int key, vector<int> vec)
{
    int pos = 0;
    return pos;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;
    binary_search(0, vec);
    for (auto i : vec)
        cout << i << " ";
    cout << "\n";
}
