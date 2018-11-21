#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
int merge_count(vector<int> &vec, int left, int mid, int right)
{
    int llen = mid - left, rlen = right - mid;
    int i=0, j=0, k=0, inv_count = 0;
    vector<int> tmp(right-left);
    while(i < llen && j < rlen)
        if(vec[left+i] > vec[mid+j]) // inversion criteria
            {
                tmp[k++] = vec[mid+j];
                inv_count += 1;
                printf("%d inversions w.r.t %d\n", j+1, vec[left+i]);
                j++;
            }
        else 
            tmp[k++] = vec[left+i++];
    while(i < llen)
        tmp[k++] = vec[left+i++];
    while(j < rlen)
        tmp[k++] = vec[mid+j++];

    cout << "before merge: ";
    for(int &i:vec)
        cout << i << " ";
    cout << "\n";
    std::copy(tmp.begin(), tmp.end(), vec.begin()+left);
    cout << "after merge: ";
    for(int &i:vec)
        cout << i << " ";
    cout << "\n";
    cout << "#inv: " << inv_count << "\n"; 
    return inv_count;
}
int count(vector<int> &vec, int left, int right)
{
    int j = left, mid = (left+right)/2;
    if(right - left == 2)
    {
        if(vec[j] > vec[j+1])
        {
            std::swap(vec[j], vec[j+1]);
            return 1;
        }
        else   
            return 0;
    }
    if(right - left == 1) return 0;
    int c1 = count(vec, left, mid);
    int c2 = count(vec, mid, right);
    return c1 + c2 + merge_count(vec, left, mid, right);
}
int main()
{
    int k = 3;
    vector<int> v;
    vector<int> tmp;
    // for(auto &i: v)
    //     std::cin >> i;
    v = std::vector<int> ({25, 7, 10, 4, 3, 20, 15});
    v = std::vector<int> ({ 2, 1, 3, 1, 2 });
    int cnt = count(v, 0, v.size());

    // tmp = vector<int>({2,2,2});
    // std::copy(tmp.begin(), tmp.end(), v.begin()+3-1);
    for(int &i:v)
        cout << i << " ";
    cout << "\n";
    cout << cnt << "\n";
    
}