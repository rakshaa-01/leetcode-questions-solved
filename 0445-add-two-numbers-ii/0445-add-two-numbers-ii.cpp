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
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead=new ListNode(-1);
        ListNode* curr=dummyHead;
        ListNode* t1=l1;
        ListNode* t2=l2;
        int c=0;
        while(t1 || t2) {
            int sum=c;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;

            ListNode* newListNode=new ListNode(sum%10);
            c=sum/10;

            curr->next=newListNode;
            curr=curr->next;

            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }

        if(c) {
            ListNode* newListNode=new ListNode(c);
            curr->next=newListNode;
        }
        return dummyHead->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head11=reverseList(l1);
        ListNode* head22=reverseList(l2);
        ListNode* temp=addTwoNumbers1(head11, head22);
        return reverseList(temp);
    }
};