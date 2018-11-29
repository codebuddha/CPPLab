/*
 * neighbours_of_median.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
int partition_fn(vector<int> &vec, int left, int right)
{
    int pivot = vec[left], pos = left+1;
    for(int i=left+1; i<=right; i++)
        if(vec[i] < pivot)
            std::swap(vec[i], vec[pos++]);
    std::swap(vec[left], vec[pos-1]);
    return pos-1;
}
void arrange_kth_pos(vector<int> &vec, int left, int right, int k)
{
    while(left <= right)
    {
        int pos = partition_fn(vec, left, right);
        if(pos == k)
            return;
        else if(pos < k) 
            left = pos+1;
        else    
            right = pos-1;
    }
}
std::pair<int, int> get_neighbours_of_median(vector<int> &vec)
{
    int med = vec.size()/2;
    arrange_kth_pos(vec, 0, vec.size()-1, med);
    arrange_kth_pos(vec, 0, med-1, med-1);
    arrange_kth_pos(vec, med+1, vec.size()-1, med+1);
    cout << vec[med-1] << " " << vec[med+1] << "\n";
    return {vec[med-1], vec[med+1]};
}
int main()
{
    vector<int> a = {31, 32, 39, 30, 29, 25, 20, 33, 21};
    auto x = get_neighbours_of_median(a);
    cout << x.first << " " << x.second << "\n";
}