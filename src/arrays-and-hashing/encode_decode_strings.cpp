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

string encode(vector<string> &strs) {
    string res;
    for (const string &s : strs) {
        res += to_string(s.size()) + "#" + s;
        cout << res << endl;
    }
    return res;
}

vector<string> decode(string s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
        int j = i;
        string l;
        while (s[j] != '#') {
            l += s[j];
            j++;
        }
        int length = stoi(l);
        cout << length << endl;
        i = j + 1;
        res.push_back(s.substr(i, length));
        i = i + length;
    }

    return res;
}

void solve() {
    vector<string> s = {"we","say",":","yes","!@#$%^&*()"};
    vector<string> output = decode(encode(s));
    for (auto s : output) {
        cout << s << endl;
    }
}


int main() {
    Speed();
    solve();
    return 0;
}
