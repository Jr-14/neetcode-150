// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description
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

int findMin(vector<int> &nums) {
    int lower = 0, upper = nums.size() - 1;
    while (lower < upper) {
        int mid = (lower + upper)/2;
        if (nums[mid] <= nums[upper]) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }
    return nums[lower];
}

void solve() {
    vector<int> v = {5,6,7,0,1,2,4};
    cout << findMin(v) << endl;
}


int main() {
    Speed();
    solve();
    return 0;
}
