/*
 * MergeSort.cpp
 * Created on: 28-11-2018
 * Author: Abhirup
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
template<typename T>
vector<T> merge(vector<T> &a, vector<T> &b)
{
    int i=0, j=0, k=0, m = a.size(), n = b.size();
    vector<T> c(m + n);
    while(i < m && j < n)
        if(a[i] < b[j])
            c[k++] = a[i++];
        else 
            c[k++] = b[j++];
    while(i < m)
        c[k++] = a[i++];
    while(j < n)
        c[k++] = b[j++];

        
    return c;
}
template<typename T>
void merge_sort(vector<T> &vec)
{
    if(vec.size() == 1)
        return;
    if(vec.size() == 2 && vec[1] < vec[0])
    {
        std::swap(vec[1], vec[0]);
        return;
    }
    int mid = vec.size()/2;
    vector<T> 
        leftvec (vec.begin(), vec.begin()+mid), 
        rightvec (vec.begin()+mid, vec.end());
    
    merge_sort(leftvec);
    merge_sort(rightvec);
    vec = merge(leftvec, rightvec);
}
int main()
{
    int tmp;
    std::vector<int> v;
    // for(auto &i: v)
    //     std::cin >> i;
    v = std::vector<int> ({10, 23, 7, 2, 0, 500, 9});
    merge_sort(v);
    for(auto &i:v)
        std:: cout << i << " ";
    std::cout << "\n";
}