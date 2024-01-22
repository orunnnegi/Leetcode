/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> store;
        ListNode *trav = head;
        while(trav)
        {
            store.push_back(trav -> val);
            trav = trav -> next;
        }
        int ind = 0;
        trav = head;
        sort(store.begin(), store.end());
        while(trav)
        {
            trav -> val = store[ind++];
            trav = trav -> next;
        }
        return head;
    }
};