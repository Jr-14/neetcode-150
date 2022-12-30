/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

// #include <bits/stdc++.h> // Use only when importing from a Linux machine
#include <algorithm>
#include <iterator>
#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

//TODO: Change method signature
vector<int> topKFrequent(vector<int>& nums, int k) {
    int numSize = nums.size();
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }

    // Create a vector of vectors for the counts
    vector<vector<int>> countVector(numSize + 1);
    for (const auto & [key, value] : countMap) {
        countVector[value].push_back(key);
    }   

    // Create the output vector
    vector<int> output;
    for (int i = numSize; i >= 0; i--) {
        vector<int> numbers = countVector[i];
        int remaining = k - output.size();
        if (remaining > 0) {
            int numbersToAdd = min(remaining, (int)numbers.size());
            for (int j = 0; j < numbersToAdd; j++) {
                output.push_back(numbers[j]);
            }
        }
    }
    return output;
}

int main(int argc, char** argv) {
    vector<int> nums = {-1, -1};
    int k  = 1;
    vector<int> output = topKFrequent(nums, k);
    for (int out : output) {
        cout << out << endl;
    }
    return 0;
}
