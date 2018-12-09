/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pre;
    int ref=0x7fffffff;
    TreeNode* tag;
    void f(TreeNode* root){
        if(root==NULL)
            return ;
        if(root==tag)
        {
            pre=root->val;
            f(root->right);
            return ;
        }
        f(root->left);
        int cnt=abs(root->val-pre);
        if(cnt<ref){
            ref=cnt;
        }
        //cout<<root->val<<endl;
        pre=root->val;
        f(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        TreeNode *T=root;
        while(T->left!=NULL){
            T=T->left;
        }
        tag=T;
        f(root);
        return ref;
    }
};
