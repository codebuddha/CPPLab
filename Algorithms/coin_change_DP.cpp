#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
int main()
{
    int tot, n;
    std::cin >> tot >> n;
    std::vector<int> coins(n);
    for(auto &i:coins)
        std::cin >> i;
    std::vector<int> mC(tot+1);
    for(int i=1; i<=tot; i++)
        mC[i] = INT16_MAX;
    for(int i=coins[0]; i<=n; i++)
    {
        for(auto &j:mC)
            std::cout << j << "\t";
        std::cout  << "\n";
        int minm = INT16_MAX;
        for(auto &j:coins)
            minm = std::min(minm, mC[tot-j]);
        mC[i] = std::min(mC[i], minm+1);
        
    }
    std::cout << "\n"; 
}