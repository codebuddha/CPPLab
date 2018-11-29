/*
 * RadixSort.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cin;
using std::cout;
using vi = vector<int>;
int numDig(int x)
{
    return x>0 ? std::log10 (double(x)) + 1 : 1;
}
void count_sort_k(vi &a, int k)
{
    vi carr(10), aux(a.size());
    int len = numDig(a[0]);
    // cout << "check " << int(12345 / pow10(len-k-1)) % 10 << "\n";
    for(auto &i : a)
    {
        int cidx = int(i / pow10(len-k-1)) % 10;
        carr[cidx] ++;
    }
    carr[0]--;
    for(int i=1; i<carr.size(); i++)
        carr[i] += carr[i-1];
    for(int i=a.size()-1; i>=0; i--)
    {
        int cidx = int(a[i] / pow10(len-k-1)) % 10;
        int aidx = carr[cidx]--;
        aux[aidx] = a[i];
    }
    a = aux;

    for(auto &i: aux)
        std::cout << i << ' ';
    std::cout << '\n';
}
void radix_sort(vi &a)
{
    int len = numDig(a[0]);
    for(int i=len-1; i>=0; i--)
        count_sort_k(a, i);
}
int main()
{
    vi a = {123, 231, 345, 456, 789, 111, 222, 234};
    radix_sort(a);
}