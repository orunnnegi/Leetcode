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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int , vector<int>, greater<int>> pq;
        for(ListNode* it: lists)
        {
            while(it)
            {
                pq.push(it -> val);
                it = it -> next;
            }
        }
        if(pq.empty())
        {
            return NULL;
        }
        ListNode * head = new ListNode();
        if(pq.empty() == false)
        {
            head -> val = pq.top();
            pq.pop();
        }
        ListNode *temp = new ListNode();
        temp = head;
        while(!pq.empty())
        {
            int element = pq.top();
            temp -> next = new ListNode(element);
            temp = temp -> next;
            pq.pop();
        }
        

        return head;
    }
};