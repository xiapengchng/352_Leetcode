/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<stdlib.h>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *L,*L1,*p;
        int val;
        L=(struct ListNode*)malloc(sizeof(struct ListNode));
        L1=L;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<=l2->val){
                val=l1->val;
                l1=l1->next;
            }
            else{
                val=l2->val;
                l2=l2->next;
            }
            //cout<<val<<endl;
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->val=val;
            p->next=NULL;
            L->next=p;
            L=p;
        }
        while(l1!=NULL){
            val=l1->val;
            l1=l1->next;
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->val=val;
            p->next=NULL;
            L->next=p;
            L=p;
        }
        while(l2!=NULL){
            val=l2->val;
            l2=l2->next;
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->val=val;
            p->next=NULL;
            L->next=p;
            L=p;
        }
        return L1->next;
    }
};
