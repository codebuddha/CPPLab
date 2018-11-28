/*
 * kth_order_QuickSelect.cpp
 * Created on: 28-11-2018
 * Author: Abhirup
*/
#include <iostream>
#include <stdio.h>
#include <vector>

int partition_fn(std::vector<int> &a, int start, int end)
{
    int pivot = a[start], pos = start+1;
    for(int i=start+1; i<=end; i++)
        if(a[i] < pivot)
        {
            std::swap(a[i], a[pos]);
            pos++;  
        }    
    std::swap(a[start], a[pos-1]);
    return pos-1;
}
int kth_smallest(std::vector<int> &vec, int k)
{
    int left=0, right=vec.size()-1;
    do{
        int pos = partition_fn(vec, left, right);
        if(pos == k)
        {
            return vec[pos]; 
        }
        else if(pos > k)
        {
            right = pos - 1;
        }
        else if(pos < k)
        {
            left = pos + 1;
        }
    }while(left <= right);
}
int main()
{
    int k = 3;
    std::vector<int> v;
    v = std::vector<int> ({7, 10, 4, 3, 20, 15});
    std::cout << "k-th: " << kth_smallest(v, k-1) << "\n";
}