"""
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
"""

from typing import List
import unittest

def max_area(height: List[int]) -> int:
    area = 0
    left, right = 0, len(height) - 1
    while(left < right):
        new_area = (right - left) * min(height[left], height[right])
        area = max(area, new_area)
        if height[left] < height[right]:
            left = left + 1
        else:
            right = right - 1
    return area



class Test(unittest.TestCase):
    def test_example_one(self):
        height = [1,8,6,2,5,4,8,3,7]
        output = 49
        self.assertEqual(max_area(height), output)

    def test_example_two(self):
        height = [1, 1]
        output = 1
        self.assertEqual(max_area(height), output)

    def test_example_three(self):
        height = [1, 1, 1, 1, 1, 1, 1, 1, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        output = 18
        self.assertEqual(max_area(height), output)

if __name__ == "__main__":
    unittest.main()