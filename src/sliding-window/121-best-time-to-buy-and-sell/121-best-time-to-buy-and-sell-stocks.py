"""
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

"""

from typing import List
import unittest

def max_profit(prices):
    """
    :type prices: List[int]
    :rtype: int
    """
    if len(prices) < 2:
        return 0
    profit = 0
    i = 0
    for j in range(1, len(prices)):
        if prices[i] >= prices[j]:
            i = j
            continue
        profit = max(profit, prices[j] - prices[i])
    return profit

class Test(unittest.TestCase):
    def test_example_one(self):
        prices = [7,1,5,3,6,4]
        output = 5
        self.assertEqual(max_profit(prices), output)

    def test_example_two(self):
        prices = [5, 3, 7, 11, 1, 1, 1]
        output = 8
        self.assertEqual(max_profit(prices), output)

    def test_example_three(self):
        prices = [7, 4, 12, 3, 3, 10]
        output = 8

if __name__ == "__main__":
    unittest.main()