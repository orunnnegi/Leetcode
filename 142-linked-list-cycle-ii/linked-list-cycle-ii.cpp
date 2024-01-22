/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> check;
        ListNode * trav = head;
        while(trav != NULL)
        {
            if(check.find(trav) != check.end())
            {
                return trav;
            }
            check.insert(trav);
            trav = trav -> next;
        }
        return NULL;
    }
};