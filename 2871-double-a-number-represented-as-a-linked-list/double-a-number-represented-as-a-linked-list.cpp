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
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL) return head;
        head=reverse(head);
        ListNode* temp=head;
        int c=0;
        while(temp->next!=NULL){
            int a=temp->val;
            a=a*2;
            a+=c;
            if(a>=10){
                c=a/10;
                a=a%10;
            }
            else{
                c=0;
            }
            temp->val=a;
            temp=temp->next;
        }
        int a=temp->val;
        a*=2;
        a+=c;
        if(a>=10){
            c=a/10;
            a=a%10;
        }
        else{
            c=0;
        }
        temp->val=a;
        if(c!=0){
            temp->next=new ListNode(c);
        }
        return reverse(head);
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* cur=head;
        ListNode* next;
        ListNode* prev=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
};