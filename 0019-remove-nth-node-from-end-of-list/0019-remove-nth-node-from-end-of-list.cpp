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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int N=0;
        ListNode* temp=head;
        while(temp) {
            N++;
            temp=temp->next;
        }
        int pos=N-n;
        int cnt=0;
        temp=head;
        ListNode* prev=nullptr;
        if(pos==0) return head->next;
        while(temp) {
            if(pos==cnt) {
                break;
            }
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        prev->next=temp->next;
        return head;
    }
};