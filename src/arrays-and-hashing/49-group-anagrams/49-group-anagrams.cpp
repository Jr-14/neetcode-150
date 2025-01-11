/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Constraints:
    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>

using namespace std;

string stringSort(string s) {
    int counter[26] = {0};
    for (char c : s) {
        counter[c - 'a']++;
    }
    string t;
    for (int c = 0; c < 26; c++) {
        t += string(counter[c], c + 'a');
    }
    return t;
}

map<char, int> mapString(string s) {
    map<char, int> m;
    for (char& c : s) {
        m[c]++;
    }
    return m;
}

vector<vector<string>> groupAnagramsUsingStringSort(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (string s : strs) {
        m[stringSort(s)].push_back(s);
    }

    vector<vector<string>> anagrams;
    for (auto p : m) {
        anagrams.push_back(p.second);
    }
    return anagrams;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<map<char, int>, vector<string>> mappings;
    for (string& s : strs) {
        map<char, int> ms = mapString(s);       
        if (mappings.find(ms) != mappings.end()) {
            vector<string> vs = mappings[ms];
            vs.push_back(s);
            mappings[ms] = vs;
        } else {
            vector<string> vs;
            vs.push_back(s);
            mappings[ms] = vs;
        }
    }

    vector<vector<string>> st;
    for (const auto& [k, v] : mappings) {
        vector<string> commonAnagrams;
        for (string s : v) {
            commonAnagrams.push_back(s);
        }
        st.push_back(commonAnagrams);
    }
    return st;
}

int main() {
    vector<string> strings = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ga = groupAnagrams(strings);
    return 0;
}