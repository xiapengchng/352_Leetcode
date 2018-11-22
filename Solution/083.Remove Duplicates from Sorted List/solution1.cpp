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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *h=head;
        while(head)
        {
            if(head->next!=NULL)
            {
                if(head->next->val==head->val)
                    head->next=head->next->next;
                else
                    head=head->next;
            }
            else
                head=head->next;
        }
        return h;
    }
};
