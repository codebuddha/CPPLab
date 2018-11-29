/*
 * counting_sort_dictionary.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<cmath>
using std::vector;
using std::cin;
using std::cout;
using std::string;
using vs = vector<string>;
void count_sort_k(vs &a, int k=0)
{
    vector<int> carr(26, 0);
    vs aux(a.size());
    vector<char> ch(26);
    for(int i=0; i<26; i++)
        ch[i] = char(97+i);

    for(auto &s: a)
    {
        char c = s[k];
        carr[c-97]++;
    }

    carr[0]--;
    for(int i=1; i<carr.size(); i++)
        carr[i] += carr[i-1];

    for(int i=a.size()-1; i>=0; i--)
    {
        int cidx = a[i][k] - 97;
        int aidx = carr[cidx]--;
        aux[aidx] = a[i];
    }

    for(auto &i: aux)
        std::cout << i << ' ';
    std::cout << '\n';

    a = aux;
}
void radix_sort(vs &a)
{
    int len = a[0].length();
    for(int i=len-1; i>=0; i--)
        count_sort_k(a, i);
}
int main()
{
    vs a = {"mall", "fall", "falk", "palk", "aalk", "balk"};
    radix_sort(a);

    cout << "sorted:\n";
    for(auto &i: a)
        std::cout << i << ' ';
    std::cout << '\n';
}