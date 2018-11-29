/*
 * min_coin_change.cpp
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
int maxval = 999;
void aux(int tot, vi &coins)
{
    vi arr(tot+1, maxval), parts(tot+1, -1);
    arr[0] = 0;

    for(int i=0; i<coins.size(); i++)
    {
        int coin = coins[i], l=0;
        for(int j=coin; j<arr.size(); j++)
        {
            if (arr[j] == maxval && arr[j-coin] == maxval)
                continue;
            if(arr[j] > 1 + arr[j-coin])
            {
                arr[j] = 1 + arr[j-coin];
                parts[j] = coin;
            }
        }
    }
    cout << tot << " = ";
    while(tot > 0)
    {
        cout << parts[tot] << " ";
        tot -= parts[tot];
    }
    cout << "\n";
}
int main()
{
    vi coins = {7, 2, 3, 1};
    int tot = 13;
    aux(tot, coins);
}