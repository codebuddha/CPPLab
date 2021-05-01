#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i=0; i< nums.size(); i++) {
        int tofind = target - nums[i];
        if (hash.find(tofind) != hash.end()) { // if found
            result.push_back(hash[tofind]);
            result.push_back(i);
        }
        hash[nums[i]] = i;
    }
    return result;
}
int main() {
    vector<int> test_nums {1, 2, 3, 4, 5, 99};
    int test_target = 100;
    for (auto &i: twoSum(test_nums, test_target) ){
        cout << i << "\n";
    }
}
