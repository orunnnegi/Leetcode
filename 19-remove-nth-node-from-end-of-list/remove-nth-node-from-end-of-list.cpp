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
    int count(ListNode *head){
        int c= 1;
        while(head!=NULL && head->next!=NULL){
            c++;
            head= head->next;
        }
        return c;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        if(head->next==NULL && n==1) return NULL;
        int c= count(head);
        cout<<c;
        int i  =0; 
        ListNode *trav= head;
        ListNode *temp=head;
        int check= (c-n);
        if(check==0){
            head= head->next;
            return head;
        }
        while(i<=c){
            
            if(i==check){
                temp->next= trav->next;
                break;
            }
            if(i==(check-1)) temp= trav;
            i++; trav= trav->next;
        }
        return head;
    }
};