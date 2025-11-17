class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode* curr = dummy;
        ListNode* prev;
        ListNode* succ;

        while (curr->next) {
            prev = curr->next;
            succ = prev->next;

            bool duplicate = false;

            while (succ && succ->val == prev->val) {
                duplicate = true;
                succ = succ->next;
            }

            if (duplicate) {
                curr->next = succ;
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
