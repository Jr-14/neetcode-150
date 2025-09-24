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
 * Space complexity O(1)
 */
void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = slow->next;
    ListNode* prev = slow->next = nullptr;
    while(second != nullptr) {
        ListNode* temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }

    ListNode* start = head;

}


int main() {
    Speed();
    int t = 1;
    solve();
    return 0;
}

