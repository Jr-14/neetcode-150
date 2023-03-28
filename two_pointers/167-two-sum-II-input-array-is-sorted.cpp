/*
* Given a 1-indexed array of integers numbers that is already sorted in 
* non-decreasing order, find two numbers such that they add up to a 
* specific target number. Let these two numbers be numbers[index1] 
* and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
*
* Return the indices of the two numbers, index1 and index2, added by one 
* as an integer array [index1, index2] of length 2.
*
* The tests are generated such that there is exactly one solution. 
* You may not use the same element twice.
*
* Your solution must use only constant extra space.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    while (true) {
        if (numbers[i] + numbers[j] < target) {
            i++;
        } 
        else if (numbers[i] + numbers[j] > target) {
            j--;
        }
        else if (numbers[i] + numbers[j] == target) {
            return {i+1, j+1};
        }
    }
}

int main() {
    vector<int> numbers {2,7,11,15};
    int target = 9;
    vector<int> ind = twoSum(numbers, target);
    cout << "i: " << ind[0] << endl;
    cout << "j: " << ind[1] << endl;
}
