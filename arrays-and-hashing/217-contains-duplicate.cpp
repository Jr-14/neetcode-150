/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Constraints:

	1 <= nums.length <= 10^5
	-10^9 <= nums[i] <= 10^9
*/
#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    if (nums.empty()) {
        return false;
    }
    unordered_map<int, int> m;
    for (auto & num : nums) {
        m[num]++;
        if (m[num] > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    bool isDuplicate = containsDuplicate(nums);
    cout << isDuplicate << endl;
    return 0;
}
