/*
 * kth_elem_merge.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using viI = vector<int>::iterator;
// int c = 0;
int kth(viI a1, viI a2, viI b1, viI b2, int k)
{
    if(a2-a1 == 0) return *(b1+k);
    if(b2-b1 == 0) return *(a1+k);
    int m1 = (a2-a1)/2, m2 = (b2-b1)/2;
    printf("m1 %d m2 %d %d\n", *(a1+m1), *(b1+m2), (*(a1+m1) > *(b1+m2)));
    // c++;
    // if(c >= 20) return 0;
    // return 0;
    if(m1 + m2 < k)
    {
        if(*(a1+m1) > *(b1+m2)){
                // cout << "case1\n";
            return kth(a1, a2, b1+m2+1, b2, k-m2-1);
                }
        else{
                // cout << "case2\n";
            return kth(a1+m1+1, a2, b1, b2, k-m1-1);
        }
    }
    else
    {
        if(*(a1+m1) > *(b1+m2)){
                // cout << "case3\n";
            return kth(a1, a1+m1, b1, b2, k);}
        else{
                // cout << "case4\n";
            return kth(a1, a2, b1, b1+m2, k);}
    }
}
int main()
{
    vector<int> a = {2, 3, 6, 7, 9}, b = {1, 4, 8, 10};
    int c = kth(a.begin(), a.end(), b.begin(), b.end(), 4);
    cout << c << "\n";
}