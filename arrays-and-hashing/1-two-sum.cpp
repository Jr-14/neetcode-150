/**
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    Constraints:
        2 <= nums.length <= 104
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        Only one valid answer exists.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> sum(2);
    
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        m[num] = i;
    }

    for (int j = 0; j < nums.size(); ++j) {
        int num = nums[j];
        int remaining = target - num;
        if (m.count(remaining)) {
            int k = m[remaining];
            if (j != k) {
                vector<int> s(2);
                s = {j, k};
                return s;
            }
        } 
    }
    return sum;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> sum = twoSum(nums, target);
    cout << sum[0] << "," << sum[1] << endl;
    return 0;
}