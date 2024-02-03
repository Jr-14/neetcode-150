/*
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase 
 * letters and removing all non-alphanumeric characters, it reads the same forward 
 * and backward. Alphanumeric characters include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <vector>

using namespace std;
string sanitise(string s) {
    int len = s.size();
    vector<char> chars;

    for (int i = 0; i < len; i++) {
        if (isalnum(s[i])) {
            chars.push_back(tolower(s[i]));
        }
    }
    string newString(chars.begin(), chars.end());
    return newString;
}

bool isPalindrome(string s) {
    string sanitisedString = sanitise(s);
    int len = sanitisedString.size();
    for (int i = 0; i < len / 2; i++) {
        int end = len - i - 1;
        if (sanitisedString[i] != sanitisedString[end]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "0P";
    bool pal = isPalindrome(s);
    cout << pal;
}
