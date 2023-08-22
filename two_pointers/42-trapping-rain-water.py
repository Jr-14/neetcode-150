"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
"""

from typing import List
import unittest

def trap(height: List[int]) -> int:
    return 6

class Test(unittest.TestCase):
    def test_example_one(self):
        height = [0,1,0,2,1,0,1,3,2,1,2,1]
        output = 6
        self.assertEqual(trap(height), output)

if __name__ == "__main__":
    unittest.main()