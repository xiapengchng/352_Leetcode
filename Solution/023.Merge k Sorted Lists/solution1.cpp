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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<node> A;
        node temp;
        struct ListNode* L=new ListNode(0);
        struct ListNode* L1=L,*ptr,*vv;
    
        A.push_back(temp);
        int n=0;
        for(int i=0;i<lists.size();i++){
            ptr=lists[i];
            if(ptr==NULL)
            {
                cout<<i<<" "<<"null"<<endl;
            }
            else{
                temp.value=ptr->val;
                temp.ptr=ptr;
                A.push_back(temp);
                n++;
            } 
        }
        build(A,n);
        for(int i=1;i<=n;i++){
              cout<<i<<" "<<A[i].value<<endl;
         }
        
        node temp1;
        while(n>=1){
            temp1=A[1];
            //ListNode* p=(ListNode*)malloc(sizeof(ListNode));
            //p->val=temp1.value;
            //p->next=NULL;
            //cout<<p->val<<endl;
            L->next=temp1.ptr;
            L=temp1.ptr;
            
            if(temp1.ptr->next==NULL){
                A[1]=A[n];
                n--;
                adjust(A,1,n);
                //free(temp1.ptr);
            }
            else{
                vv=temp1.ptr;
                temp1.value=temp1.ptr->next->val;
                temp1.ptr=temp1.ptr->next;
                A[1]=temp1;
                adjust(A,1,n);
                //free(vv);
            }   
        }
        
        //ptr=L1->next;
        //free(L);
        ptr=L1->next;
        delete(L1);
        
        return ptr;
    }
    class node{
        public:
        int value=0;
        struct ListNode* ptr=NULL;
        node& operator=(node& b){
            //node temp;
            this->value=b.value;
            this->ptr=b.ptr;
            return *this;
        }
        bool operator<(node b){
            return value<b.value;
        }
        
    };
    void adjust(vector<node>& A,int s,int n){
        node cnt=A[s];
        int v;
        while(s<=n/2){
            v=2*s;
            if(A[v+1]<A[v]&&v+1<=n)
                v=v+1;
            if(A[v]<cnt){
                A[s]=A[v];
                s=v;
            }
            else
                break;
        }
        A[s]=cnt;
    }
    void build(vector<node>& A,int n){
        int i;
        for(i=n/2;i>=1;i--)
            adjust(A,i,n);
    }
    