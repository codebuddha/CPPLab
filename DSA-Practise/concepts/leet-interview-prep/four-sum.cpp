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

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int left = j + 1, right = n - 1, two_sum_target = target - nums[i] - nums[j];
            while (right > left) {
                /* cout << low << " " << high << "\n"; */
                int pointer_sum = nums[left] + nums[right];
                if (pointer_sum == two_sum_target) {
                    result.push_back(
                        vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;  // skip over duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;  // shift pointer to next non duplicates
                    right--;
                } else if (pointer_sum > two_sum_target) {
                    right--;
                } else if (pointer_sum < two_sum_target) {
                    left++;
                }
            }
            while (j + 1 < n && nums[j] == nums[j+1]) ++j; // skipping duplicates in pointer 2
        }
        while (i + 1 < n && nums[i] == nums[i+1]) ++i; // skipping duplicates in pointer 1
    }
    return result;
}

int main() {
    vector<int> test_nums{-4, -1, -1, 0, 1, 2, -2};
    /* vector<int> test_nums{}; */
    int test_target = 0;
    for (auto& i : fourSum(test_nums, test_target)) {
        debug_vector(i);
    }
}
