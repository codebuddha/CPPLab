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
int k_th_largest(std::vector<int> &vec, int k)
{
    int left=0, right=vec.size()-1;
    do{
        // printf("left:%d right:%d k:%d\n", left, right, k);
        int pos = partition_fn(vec, left, right);
        // printf("pos:%d\n", pos);
        // for(auto &i:vec)
        //     std::cout << i << " ";
        // std::cout << "\n";
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
    printf("l:%d r:%d\n", left, right);

}
int main()
{
    int k = 3;
    std::vector<int> v;
    // for(auto &i: v)
    //     std::cin >> i;
    v = std::vector<int> ({7, 10, 4, 3, 20, 15});
    std::cout << "k-th: " << k_th_largest(v, k-1) << "\n";
}