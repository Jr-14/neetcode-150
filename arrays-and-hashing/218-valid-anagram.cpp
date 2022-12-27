/*
Given two strings 's' and 't', return true if 't' is an anagram of 's', and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> mapString(string s) {
    unordered_map<char, int> m;
    for (char& c : s) {
        m[c]++;
    }
    return m;
}

bool isAnagram(string s, string t) {
    unordered_map<char, int> sMap = mapString(s);
    unordered_map<char, int> tMap = mapString(t);
    if (sMap.size() != tMap.size()) {
        return false;
    }

    for (char& c : s) {
        if (tMap.find(c) != tMap.end()) {
            if (sMap[c] != tMap[c]) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string a = "anagram";
    string b = "nagaram";
    bool isA = isAnagram(a, b);
    cout << isA << endl;
    return 0;
}