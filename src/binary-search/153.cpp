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
        // It's been rotated
        if (nums[lower] > nums[upper]) {
            if (nums[mid] < nums[lower]) {
                upper = mid;
            } else {
                lower = mid + 1;
            }
        } else {
            upper = mid;
        }
    }
    return nums[lower];
}

void solve() {
    vector<int> v = {4,5,6,7,0,1,2};
    cout << findMin(v) << endl;
}


int main() {
    Speed();
    solve();
    return 0;
}
