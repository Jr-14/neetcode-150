// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

/**
 * Speed up cin and cout
 */
void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int search(vector<int> &nums, int target) {
    int lower = 0, upper = nums.size() - 1;
    while (lower <= upper) {
        int mid = (lower + upper)/2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[lower] <= target && target <= nums[mid]) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }
    return -1;
}

void solve() {
    vector<int> v = {5,1,3};
    cout << search(v, 5) << endl;
}


int main() {
    Speed();
    solve();
    return 0;
}
