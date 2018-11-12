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
    ListNode* swapPairs(ListNode* head) {
        ListNode* l0,*l1,*l2,*L,*p;
        l0=new ListNode(0);
        L=l0;
        l0->next=head;
        while(l0!=NULL&&l0->next!=NULL&&l0->next->next!=NULL){
            l1=l0->next;
            l2=l1->next;
            p=l1;
            l1=l2;
            l2=p;
            l2->next=l1->next;
            l1->next=l2;
            l0->next=l1;   
            l0=l2;
        }
        
        return L->next;
    }
};