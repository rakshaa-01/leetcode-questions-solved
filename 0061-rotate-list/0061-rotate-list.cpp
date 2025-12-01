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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=1;
        ListNode* temp=head;
        while(temp->next) {
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;
        
        temp->next=head;
        int req=len-k;  //right rotation this one = striver's
        //(If left rotation, here req=k, rest all same)
        int c=1;
        
        temp=head;
        while(temp) {
            if(c==req) break;
            c++;
            temp=temp->next;
        }
        ListNode* newHead=temp->next;
        temp->next=nullptr;
        return newHead;
    }
};