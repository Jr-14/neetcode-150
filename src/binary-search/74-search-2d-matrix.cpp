// https://leetcode.com/problems/search-a-2d-matrix/description/
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

int searchMatrix(vector<vector<int>> &matrix, int target) {
    vector<int> nums;
    for (const vector<int> &v : matrix) {
        if (target <= v[v.size() - 1]) {
            if (target == v[v.size() - 1]) {
                return true;
            }
            nums = v;
            break;
        }
    }
    for (auto n : nums) {
        cout << n << endl;
    }
    int l = 0, u = nums.size() - 1;
    while (l <= u) {
        int k = (l + u)/2;
        if (nums[k] == target) {
            return true;
        }
        if (nums[k] > target) {
            u = k - 1;
        } else {
            l = k + 1;
        }
    }
    return false;
}

void solve() {
    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << searchMatrix(v, 3) << endl;
}


int main() {
    Speed();
    int t = 1;
    solve();
    return 0;
}
