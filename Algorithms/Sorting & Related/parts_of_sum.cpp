/*
 * parts_of_sum.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using std::vector;
using std::cin;
using std::cout;
std::pair<int,int> aux(vector<int> vec, int sum)
{
    std::sort(vec.begin(), vec.end());
    for(auto &i: vec)
        std::cout << i << ' ';
    std::cout << '\n';
    int left = 0, right = vec.size()-1;
    while(left <= right)
    {
        printf("left %d right %d\n", vec[left], vec[right]);
        int csum = vec[left] + vec[right];
        if(csum == sum)
            return {left, right};
        if(csum < sum)
            left++;
        if(csum > sum)
            right--; 
    }
}
int main()
{
    std::vector<int> v;
    // for(auto &i: v)
    //     std::cin >> i;
    v = std::vector<int> ({10, 23, 7, 2, 0, 500, 9});
    aux(v, 9);
}