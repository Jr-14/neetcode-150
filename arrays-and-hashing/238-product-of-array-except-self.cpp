/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 
Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> product(nums.size());
    int prefix = 1;
    product[0] = prefix;
    for (int i = 0; i < nums.size() - 1; i++) {
        prefix = prefix * nums[i];
        product[i+1] = prefix;
    }
    prefix = 1;
    for (int i = nums.size() - 1; i > 0; i--) {
        prefix = prefix * nums[i];
        product[i-1] = product[i-1] * prefix;
    }
    return product;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> out = productExceptSelf(nums);
    return 0;
}