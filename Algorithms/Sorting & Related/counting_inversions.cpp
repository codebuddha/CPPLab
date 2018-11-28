/*
 * counting_inversions.cpp
 * Created on: 28-11-2018
 * Author: Abhirup
 * Hackerrank problem: https://www.hackerrank.com/challenges/ctci-merge-sort/problem
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
int count = 0;
template<typename T>
vector<T> second_count(vector<T> &a, vector<T> &b)
{
    int i=0, j=0, k=0, m=a.size(), n=b.size();
    vector<T> c(m + n);
    while(i < m && j < n)
        if(a[i] <= b[j])
            c[k++] = a[i++];
        else 
        {
            c[k++] = b[j++];
            count += m-i;
        }
    while(i < m)
        c[k++] = a[i++];
    while(j < n)
        c[k++] = b[j++];
    return c;
}
template<typename T>
void first_count(vector<T> &vec)
{
    // defining base cases
    if(vec.size() == 1)
        return;
    if(vec.size() == 2)
    {
        if(vec[1] < vec[0])
        {
            std::swap(vec[0], vec[1]);
            count++;
        }
        else
            return;
    }  
    // now, for the recursive cases
    int mid = vec.size()/2;
    vector<T> 
        leftvec = vector<T> (vec.begin(), vec.begin()+mid),
        rightvec = vector<T> (vec.begin()+mid, vec.end());
    first_count(leftvec);
    first_count(rightvec);
    vec = second_count(leftvec, rightvec);
}
int main()
{
    int tc;
    std::vector<int> v;
    for(auto &i: v)
        std::cin >> i;
    v = std::vector<int> ({10, 23, 7, 2, 0, 500, 9}); // ans=12
    // v = std::vector<int> ({ 2, 1, 3, 1, 2});// ans = 4
    first_count(v);
    // for(auto &i:v)
    //     std:: cout << i << " ";
    // std::cout << "\n";
    cout << count << "\n";
}