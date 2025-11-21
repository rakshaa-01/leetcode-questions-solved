/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* del_node) {
        del_node->val=del_node->next->val;
        ListNode* temp=del_node->next;
        del_node->next=del_node->next->next;
        // delete del_node;
    }
};