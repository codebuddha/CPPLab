/*
 * bitonic_sequence_Peak.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
int find_bitonic_peak(vector<int> &vec)
{
    int left=0, right=vec.size()-1, mid=0;
    while(left <= right)
    {
        mid = (left+right)/2;
        printf("left %d right %d @mid %d\n", vec[left], vec[right], vec[mid]);
        if(vec[mid] > vec[mid-1] && vec[mid] > vec[mid+1])
            return mid;
        if(vec[mid-1] > vec[mid])
            {
                right = mid-1;
                cout << "move left\n";
            }
        else if(vec[mid] < vec[mid+1])
            {
                left = mid+1;
                cout << "move right\n";
            }
        else break;
    }
    return mid;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 10, 10, 10, 9, 8, 1};
    int x = find_bitonic_peak(v);
}