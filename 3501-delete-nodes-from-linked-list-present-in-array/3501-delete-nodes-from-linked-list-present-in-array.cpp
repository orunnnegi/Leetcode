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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Create a dummy node to simplify edge cases where the head needs to be removed
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        
        while (current->next != nullptr) {
            if (numSet.find(current->next->val) != numSet.end()) {
                // Remove the node
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        
        return dummy.next;
    }
};