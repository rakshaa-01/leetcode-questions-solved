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
    ListNode* sortList(ListNode* head) {
        vector<int> res;
        ListNode* temp=head;
        while(temp) {
            res.push_back(temp->val);
            temp=temp->next;
        }
        sort(res.begin(), res.end());
        temp=head;
        int g=0;
        while(temp) {
            temp->val=res[g++];
            temp=temp->next;
        }
        return head;
    }
};