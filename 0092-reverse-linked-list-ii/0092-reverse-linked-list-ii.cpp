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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* tmp;
        for (int idx = 0; idx < left - 1; idx++) {
            prev = prev->next;
            curr = curr->next;
        }
        for (int idx = 0; idx < right - left; idx++) {
            tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy->next;
    }
};