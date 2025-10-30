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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp=head;
        while(temp) {
            cnt++;
            temp=temp->next;
        }
        int firstFew=cnt%k;
        int nextFew=k-firstFew;
        int elem=cnt/k;
        //firstFew no elts = elem+1
        //N-firstFew = elem

        vector<ListNode*> v;
        temp=head;
        while(firstFew>0) {
            ListNode* dummyNode=new ListNode(-1);
            ListNode* copy=dummyNode;
            for(int i=0; i<elem+1 && temp; i++) {
                ListNode* newNode=new ListNode(temp->val);
                copy->next=newNode;
                copy=copy->next;
                temp=temp->next;
            }
            v.push_back(dummyNode->next);
            firstFew--;
        }

        while(nextFew>0) {
            ListNode* dummyNode=new ListNode(-1);
            ListNode* copy=dummyNode;
            for(int i=0; i<elem && temp; i++) {
                ListNode* newNode=new ListNode(temp->val);
                copy->next=newNode;
                copy=copy->next;
                temp=temp->next;
            }
            v.push_back(dummyNode->next);
            nextFew--;
        }
        return v;
    }
};