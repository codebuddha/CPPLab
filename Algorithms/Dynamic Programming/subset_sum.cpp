/*
 * subset_sum.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<vector>
#include<iostream>
#include<cmath>
using std::vector;
using std::cin;
using std::cout;
using vi = vector<int>;
void aux(int tot, vi &set)
{
    vector<vi> arr (set.size(), vi(tot+1, 0));
    for(int i=0; i<set.size(); i++)
        arr[i][0] = 1;
    
    for(int j=1; j<tot+1; j++)
        arr[0][j] = j==set[0] ? 1 : 0;
    for(int i=1; i<set.size(); i++)
    {
        int j = 1;
        for(; j<set[i]; j++)
            arr[i][j] = arr[i-1][j];
        for(; j<tot+1; j++)
            arr[i][j] = arr[i-1][j] | arr[i-1][j-set[i]];
    }

    for(int j=0; j<tot+1; j++)
        cout << j << "\t";
    cout << "\n";
    for(auto &i: arr)
    {
        for(auto &j: i)
            std::cout << j << '\t';
        std::cout << '\n';
    }
    std::cout << '\n';
}
int main()
{
    int tot = 11;
    vi set = {2, 3, 7, 8, 10};
    aux(tot, set);
}