/*
 * missing_element_in_sequence.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/

#include<vector>
#include<iostream>
#include<stdio.h>
using std::vector;
using std::cin;
using std::cout;
int find_missing(vector<int> &v)
{
    int left=0, right=v.size()-1;
    int diff = (v[right]-v[left])/v.size();
    while(left <= right)
    {
        int mid = (left+right)/2;
        // printf("left %d right %d mid %d\n", left, right, v[mid]);
        if(v[mid] - v[mid-1] != diff && mid > 0)
            return mid;
        if(v[mid+1] - v[mid] != diff)
            return mid+1;
        if(v[mid] == v[0] + mid*diff)
            left = mid+1;
        else
            right = mid-1;
    }

}
int main()
{
    vector<int> v = {4, 7, 10, 16, 19};
    int diff = (v[v.size()-1]-v[0])/v.size(); 
    int x = find_missing(v);
    printf("missing %d at pos %d\n", (v[0]+x*diff), x+1);
}