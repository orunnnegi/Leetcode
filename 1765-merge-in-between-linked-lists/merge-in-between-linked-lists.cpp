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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int size = 0;
        ListNode * temp = list1;
        ListNode * t = list1;

        while(temp)
        {
            size++;
            temp = temp -> next;
        }

        for(int ind = 0; ind < b; ind++)
        {
            t = t -> next;
        }
        cout << t -> val;
        // cout << size;
        int ind = 0;
        temp = list1;
        ListNode * prev = NULL;
        for(int ind = 0; ind < size; ind++)
        {
            prev = temp;
            temp = temp -> next;

            if(ind == a - 1)
            {
                while(ind < b - 1)
                {
                    ind++;
                    temp = temp -> next;
                }
                prev -> next = list2;
                break;
            }
        }
        temp = list1;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = t -> next;
        return list1;

    }
};