#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int count_func(int l, int r){
    int left=0, right=0;
    /* cout << l << " " << r << "\n"; */
    if (l == 0)
        left = 1;
    else if (vec[l] > 0)
        left = vec[l];
    else {
        for(int i=0; i<l; i++)
            left += count_func(i, l-i-1);
        vec[l] = left;
    }
    if (r == 0)
        right = 1;
    else if (vec[r] > 0)
        right = vec[r];
    else {
        for(int i=0; i<r; i++)
            right += count_func(i, r-i-1);
        vec[r]  = right;
    }
    return left*right;
}
int numTrees(int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += count_func(i, n-i-1);
    return sum;
}
int main(){
    int n;
    cin >> n;
    vec.resize(n+1);
    vec[0] = 0;
    vec[1] = 1;
    cout << numTrees(n) << "\n";
}
