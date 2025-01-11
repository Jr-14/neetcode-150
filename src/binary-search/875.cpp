// https://leetcode.com/problems/koko-eating-bananas/description/
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

bool comp(int a, int b) {
    return a < b;
}

int minEatingSpeed(vector<int> &piles, int target) {
    sort(piles.begin(), piles.end(), comp);
    for (auto p : piles) {
        cout << p << endl;
    }

    int l = 0, u = piles.size() - 1;
    while (l <= u) {
        int k = (l + u)/2;
        if (piles[k] == target) {
            return true;
        }
        if (piles[k] > target) {
            u = k - 1;
        } else {
            l = k + 1;
        }
    }
    return false;
}

void solve() {
    vector<int> v = {30,11,23,4,20};
    cout << minEatingSpeed(v, 3) << endl;
}


int main() {
    Speed();
    solve();
    return 0;
}
