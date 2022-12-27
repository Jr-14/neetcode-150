/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Constraints:

	1 <= nums.length <= 10^5
	-10^9 <= nums[i] <= 10^9
*/
package main

import (
	"fmt"
)

func containsDuplicate(nums []int) bool {
	m := make(map[int]int)
	for _, s := range nums {
		if _, ok := m[s]; ok {
			return true
		}
		m[s] = s
	}
	return false
}

func main() {
	array := []int{1, 2, 3, -2, 5, -2}
	fmt.Println(containsDuplicate(array))
}
