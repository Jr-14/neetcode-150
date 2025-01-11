// https://leetcode.com/problems/binary-search/description/
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
    int l = 0, u = nums.size() - 1;
    while (l <= u) {
        int k = (l + u)/2;
        if (nums[k] == target) {
            return k;
        }
        if (nums[k] > target) {
            u = k - 1;
        } else {
            l = k + 1;
        }
    }
    return -1;
}

void solve() {

}


int main() {
    Speed();
    int t = 1;
    solve();
    return 0;
}
