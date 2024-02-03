"""
Given a string s, find the length of the longest
substring
without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
"""

from typing import List
import unittest

def longest_substring(s):
    char_set = set()
    left, max_len = 0, 0
    for right in range(len(s)):
        while s[right] in char_set:
            char_set.remove(s[left])
            left += 1
        char_set.add(s[right])
        max_len = max(max_len, right - left + 1)
    return max_len

class Test(unittest.TestCase):
    def test_example_one(self):
        s = "abcabcbb"
        output = 3 
        self.assertEqual(longest_substring(s), output)

    def test_example_two(self):
        s = "pwwkew"
        output = 3 
        self.assertEqual(longest_substring(s), output)

    def test_example_three(self):
        s = "dvdf"
        output = 3
        self.assertEqual(longest_substring(s), output)

    def test_example_four(self):
        s = "anviaj"
        output = 5
        self.assertEqual(longest_substring(s), output)

    def test_example_five(self):
        s = "abccdef"
        output = 4
        self.assertEqual(longest_substring(s), output)
    
    def test_example_six(self):
        s = " "
        output = 1
        self.assertEqual(longest_substring(s), output)

    def test_example_seven(self):
        s = "ab"
        output = 2
        self.assertEqual(longest_substring(s), output)

    def test_example_eight(self):
        s = "abba"
        output = 2
        self.assertEqual(longest_substring(s), output)

if __name__ == "__main__":
    unittest.main()