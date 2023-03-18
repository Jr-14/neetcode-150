/*
    Given an array of integers temperatures represents the daily temperatures,
    return an array answer such that answer[i] is the number of days you have
    to wait after the ith day to get a warmer temperature. If theere is no future
    day for which this is possible, keep answer[i] == 0;
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> longestDays;
    for (int i =0; i < temperatures.size(); i++) {
        longestDays.push_back(0);
    }

    vector<int> stack;
    stack.push_back(0);
    for (int i = 1; i < temperatures.size(); i++) {
        // Current temp greater than what's in the stack
        while (stack.size() && temperatures[i] > temperatures[stack.back()]) {
            longestDays[stack.back()] = i - stack.back();
            stack.pop_back();
        }
        stack.push_back(i);
    }
    return longestDays;
}

int main() {
    vector<int> input {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> temperatures = dailyTemperatures(input);
    for (int i = 0; i < temperatures.size(); i++) {
        cout << temperatures[i] << ", ";
    }
    cout << endl;
}
