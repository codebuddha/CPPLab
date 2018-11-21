/*
 * QuickMedian.cpp
 * Created on: 21-11-2018
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
int k_th_largest(std::vector<int> &vec, int k, int start, int end)
{
    if (end > vec.size()-1 && start < 0) 
    {
        std::cout << "Invalid start, end parameters\n";
        return 0;
    }  
    int left=start, right=end;
    do{
        int pos = partition_fn(vec, left, right);
        printf("current left %d right %d pos %d\n", left, right, pos);
        if(pos == k)
        {
            for(auto &i:vec)
                std::cout << i << " ";
            printf("found mid: %d\n", vec[pos]);
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
float get_median(std::vector<int> &vec)
{
    int len = vec.size();
    int mid = k_th_largest(vec, len/2, 0, vec.size()-1);
    if(len % 2 == 0)
    {
        int pre_mid = k_th_largest(vec, len/2-1, 0, len/2);
        return (pre_mid + mid)/2.0;
    }
    else{
        return mid;
    }
}
int main()
{
    int k = 3;
    std::vector<int> v;
    v = std::vector<int> ({10, 23, 7, 2, 0, 500, 81, 9});
    std::cout << "median: " << get_median(v) << "\n";
    
}