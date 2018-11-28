#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

template<typename T>
int partition_fn(vector<T> &vec, int start, int end)
{
    T pivot = vec[0]; 
    int pos = start+1;
    for(int i=start+1; i<=end; i++)
        if(vec[i] < pivot)
            std::swap(vec[pos++], vec[i]);
    std::swap(vec[start], vec[pos-1]);
    return pos-1;
}
template<typename T>
void kth_smallest(vector<T> &vec, int k, int left, int right)
{
//    int left = 0, right = vec.size()-1;
    do
    {
        int pos = partition_fn(vec, left, right);
//        printf("left %d right %d pos %d\n", left, right, pos);
        for(auto &i : vec)
            cout << i << " ";
        cout << "\n";
        if(pos == k)
            return;
        else if(pos < k)
            left = pos + 1;
        else 
            right = pos - 1;
        
    } while (left <= right);
}
template<typename T>
double get_median(vector<T> &vec)
{
    int len = vec.size();
    kth_smallest(vec, len/2, 0, len-1);
    double mid = vec[len/2];
    if(len % 2 == 0)
    {
        kth_smallest(vec, len/2-1, 0, len/2);
        return (mid + vec[len/2-1])/2.0;
    }
    return mid;
}
int main()
{
    std::vector<int> v;
    v = std::vector<int> ({10, 23, 7, 2, 0, 500, 81, 9});
    std::cout << "median: " << get_median(v) << "\n";
}
