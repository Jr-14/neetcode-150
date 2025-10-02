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

string longestCommonPrefix(vector<string> &strs) {
    string lcp = "";

    if (strs.size() == 0) {
        return lcp;
    } 

    if (strs.size() == 1) {
        return strs[0];
    }

    lcp = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        string s = strs[i];
        string newlcp = "";
        for (int j = 0; j < s.size(); j++) {
            if (j == lcp.size()) {
                break;
            }
            if (s[j] == lcp[j]) {
                newlcp += s[j];
            } else {
                break;
            }
        }
        lcp = newlcp;
    }

    return lcp;
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
