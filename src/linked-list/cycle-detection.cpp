#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Speed up cin and cout
 */
void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {

}

/**
 * Time complexity O(n)
 * Space complexity O(n)
 */
bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> seen;
    ListNode* curr = head;

    while(curr) {
        if (seen.find(curr) != seen.end()) {
            return true;
        }
        seen.insert(curr);
        curr = curr->next;
    }

    return false;
}


int main() {
    Speed();
    int t = 1;
    solve();
    return 0;
}

