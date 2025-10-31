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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        int cnt=0;
        while(temp) {
            cnt++;
            temp=temp->next;
        }
        int pos=cnt/2;
        int i=0;
        temp=head;
        ListNode* prev=head;
        if(pos==0) return head->next;
        while(temp) {
            if(i==pos) break;
            i++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=prev->next->next;
        delete temp;
        return head;
    }
};