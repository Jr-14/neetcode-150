// https://leetcode.com/problems/koko-eating-bananas/description/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

/**
 * Speed up cin and cout
 */
void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int minEatingSpeed(vector<int> &piles, int h) {
    int max = *max_element(piles.begin(), piles.end());

    int lower = 1, upper = max;
    int answer = -1;
    while (lower <= upper) {
        int mid = lower + (upper - lower)/2;
        long long totalHours = 0;
        for (auto pile : piles) {
            totalHours += ceil((double)pile/mid);
        }

        if (totalHours <= h) {
            answer = mid;
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    return answer;
}

void solve() {
    // vector<int> v = {30,11,23,4,20};
    vector<int> v = {312884470};
    cout << minEatingSpeed(v, 968709470) << endl;
}


int main() {
    Speed();
    solve();
    return 0;
}
