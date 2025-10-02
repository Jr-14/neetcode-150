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

void solve() {

}

vector<int> getConcatenation(vector<int> &nums) {
    vector<int> ans;
    for (const int& i : nums) {
        ans.push_back(i);
    }
    for (const int& i : nums) {
        ans.push_back(i);
    }
    return ans;
}


int main() {
    Speed();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
