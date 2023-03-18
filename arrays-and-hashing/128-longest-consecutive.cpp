/*
Given an unsorted array of integers nums,
return the length of the longest consecutve elements sequence.
You must write an algorithm that runs in O(n) time.
*/

#include <vector>
#include <iostream>
#include <set>

using namespace std;

int longestConsecutive(vector<int> &nums) {
    set<int> numbers;
    for (int i = 0; i < nums.size(); i++) {
        numbers.insert(nums[i]);
    }

    int longest = 0;
    int consecutive = 0;
    for (int i = 0; i < nums.size(); i++) {
        auto leftNeighbour = numbers.find(nums[i] - 1);
        // Start of the sequence
        if (leftNeighbour == numbers.end()) {
            consecutive = 1;
            while (true) {
                auto rightNeighbour = numbers.find(nums[i] + consecutive);
                if (rightNeighbour == numbers.end()) {
                    break;
                }
                consecutive += 1;
            }
        }
        if (consecutive > longest) {
            longest = consecutive;
        }
        consecutive = 0;
    }
    return longest;
}

int main() {
    vector<int> nums {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int longest = longestConsecutive(nums);
    cout << longest << endl;
}