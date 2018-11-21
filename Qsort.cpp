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
void quick_sort(std::vector<int> &vec, int start, int end)
{
    if(start < end)
    {
        int pos = partition_fn(vec, start, end);
        quick_sort(vec, start, pos);
        quick_sort(vec, pos+1, end);
    }   
    return;
}
int main()
{
    int tmp;
    std::vector<int> v(7, 0);
    for(auto &i: v)
        std::cin >> i;

    quick_sort(v, 0, v.size()-1);
    for(auto &i:v)
        std:: cout << i << " ";
    std::cout << "\n";
}