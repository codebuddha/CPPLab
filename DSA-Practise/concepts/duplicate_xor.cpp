#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums){
    int duplicate = 0;
    for(auto &i: nums){
        int key = abs(i);
        int val = nums[key];
        if (val > 0)
            nums[abs(i)] = -val;
        else {
            duplicate = key;
            break;
        }
        for(auto j: nums)
            cout << j << " ";
        cout << "\n";
    }
    return duplicate;
}
int main(){
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(auto &i: vec)
        cin >> i;
    cout << findDuplicate(vec) << "\n";
}
