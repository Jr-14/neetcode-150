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
    l, r = 0, len(height) - 1
    maxLeft, maxRight = height[l], height[r]
    volume = 0
    while l < r:
        if maxLeft <= maxRight:
            l += 1
            maxLeft = max(maxLeft, height[l])
            volume += maxLeft - height[l]
        else:
            r -= 1
            maxRight = max(maxRight, height[r])
            volume += maxRight - height[r]

    return volume

class Test(unittest.TestCase):
    def test_example_one(self):
        height = [0,1,0,2,1,0,1,3,2,1,2,1]
        output = 6
        self.assertEqual(trap(height), output)

    def test_example_four(self):
        height = [5,5,1,7,1,1,5,2,7,6]
        # 0 0 4 0 6 6 2 5 0 0 ]
        output = 23
        self.assertEqual(trap(height), output)

    def test_example_two(self):
        height = [1, 1]
        output = 0
        self.assertEqual(trap(height), output)

    def test_example_three(self):
        height = [2, 1, 1, 1, 1, 1, 1, 1, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 2]
        output = 15
        self.assertEqual(trap(height), output)

if __name__ == "__main__":
    unittest.main()