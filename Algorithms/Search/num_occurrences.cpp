/*
 * num_occurrences.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<vector>
#include<iostream>
#include<stdio.h>
using std::vector;
using std::cin;
using std::cout;
std::pair<int, int> aux(vector<int> &vec, int num)
{
    bool onlyocc = false;
    int left = 0, right = vec.size()-1, mid, fans=-1, lans=-1;
    while(left <= right)
    {
        mid = (left + right)/2;
        // printf("left %d right %d mid %d\n", left, right, vec[mid]);
        if(vec[mid] == num)
        {
            fans = mid;
            right = mid-1;
        }
        else if(vec[mid] > num)
            right = mid-1;
        else 
            left = mid + 1;
    }
    left = 0, right = vec.size()-1;
    while(left <= right)
    {
        mid = (left + right)/2;
        // printf("left %d right %d mid %d\n", left, right, vec[mid]);
        if(vec[mid] == num)
        {
            lans = mid;
            left = mid+1;
        }    
        else if(vec[mid] > num)
            right = mid-1;
        else 
            left = mid + 1;
    }
    // cout << ans << "\n";
    return {fans, lans};
}
int main()
{
    std::vector<int> v;
    // for(auto &i: v)
    //     std::cin >> i;
    v = std::vector<int> ({0, 3, 4, 5, 5, 5, 6, 7, 7, 10});
    auto ans = aux(v, 5);
    cout << (ans.second - ans.first + 1) << "\n";
}