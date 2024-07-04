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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* marker;
        int x = 0;
        ListNode* prev = head;

        while(temp){
            if(temp->val == 0){
                if(temp != prev){
                    prev->val = x;
                    x = 0;
                    prev->next = temp;
                    marker = prev;
                    prev = prev->next;
                }
            }
            else{
                x += temp->val;
            }
            temp = temp->next;
        }
        marker->next = nullptr;
        return head;
    }
};