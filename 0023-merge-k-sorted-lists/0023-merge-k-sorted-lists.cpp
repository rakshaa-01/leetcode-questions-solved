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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(!head1) return head2;
        else if(!head2) return head1;

        ListNode* temp1=head1, *temp2=head2;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(temp1 && temp2) {
            if(temp1->val<=temp2->val) {
                curr->next=temp1;
                temp1=temp1->next;
            }
            else {
                curr->next=temp2;
                temp2=temp2->next;
            }
            curr=curr->next;
        }
        curr->next=temp1? temp1: temp2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int n=lists.size();
        ListNode* head=lists[0];
        for(int j=1; j<n; j++) 
            head=mergeTwoLists(head, lists[j]);
        return lists[0];
    }
};