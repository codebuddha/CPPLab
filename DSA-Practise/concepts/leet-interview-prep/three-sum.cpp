#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
/* #include <vector> */
/* #include <unordered_map> */

using namespace std;

void debug_vector(vector<int> vec) {
    for (auto& i : vec) {
        cout << i << " ";
    }
    cout << "\n";
}

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;  // skipping over duplicates in start num
        int low = i + 1, high = nums.size() - 1, curr = nums[i];
        while (high > low) {
            /* cout << low << " " << high << "\n"; */
            int pointer_sum = nums[low] + nums[high];
            if (pointer_sum == -curr) {
                result.push_back(vector<int>{curr, nums[low], nums[high]});
                while (low < high && nums[low] == nums[low + 1])
                    low++;  // skip over duplicates
                while (low < high && nums[high] == nums[high - 1]) high--;
                low++;  // shift pointer to next non duplicates
                high--;
            } else if (pointer_sum > -curr) {
                high--;
            } else if (pointer_sum < -curr) {
                low++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> test_nums {-4, -1, -1, 0, 1, 2};
    /* vector<int> test_nums{}; */
    int test_target = 101;
    for (auto& i : threeSum(test_nums, test_target)) {
        debug_vector(i);
    }
}
