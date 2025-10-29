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
ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* curr=head;
        ListNode* before=NULL;
        ListNode* after=NULL;
        while(curr) {
            after=curr->next;
            curr->next=before;
            before=curr;
            curr=after;
        }
        return before;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverseList(head);
        ListNode* temp=head;
        ListNode* prev=head;
        int c=0;
        while(temp) {
            int prod=temp->val*2+c;
            temp->val=prod%10;
            if(prod>9) {
                c=1;
            }
            else c=0;
            prev=temp;
            temp=temp->next;
        }
        if(c) {
            ListNode* newNode=new ListNode(c);
            prev->next=newNode;
        }
        return reverseList(head);
    }
};