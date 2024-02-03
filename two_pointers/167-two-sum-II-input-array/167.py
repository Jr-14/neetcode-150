"""
Given a 1-indexed array of integers numbers that is already sorted in 
non-decreasing order, find two numbers such that they add up to a 
specific target number. Let these two numbers be numbers[index1] 
and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one 
as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. 
You may not use the same element twice.

Your solution must use only constant extra space.
"""

import unittest

def two_sum_ii(array, target):
    begin = 0
    end = len(array) - 1
    for i in range(len(array)):
        if array[begin] + array[end] > target:
            end = end - 1
        elif array[begin] + array[end] < target:
            begin = begin + 1
        else: 
            return [begin + 1, end + 1]

class Test(unittest.TestCase):
    def test_example_one(self):
        array = [2, 7, 11, 15]
        target = 9
        output = [1,2 ]
        self.assertEqual(two_sum_ii(array, target), output)

    def test_example_two(self):
        array = [2, 3, 4]
        target = 6
        output = [1 ,3]
        self.assertEqual(two_sum_ii(array, target), output)

    def test_example_three(self):
        array = [-1, 0]
        target = -1
        output = [1, 2]
        self.assertEqual(two_sum_ii(array, target), output)

if __name__ == "__main__":
    unittest.main()