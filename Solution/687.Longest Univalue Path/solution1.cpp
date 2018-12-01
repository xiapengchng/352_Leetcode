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
    int longestUnivaluePath(TreeNode* root) {
        int a;
        return f(root,a);
    }
    int f(TreeNode* root,int& L){
        if(root==NULL){
            L=0;
            return 0;
        }
        int L_lc,L_rc,a,b;
        a=f(root->left,L_lc);
        b=f(root->right,L_rc);
        int cnt=0;
        int length_l=0,length_r=0;
        if(root->left!=NULL&&root->val==root->left->val){
            cnt=cnt+L_lc+1;
            length_l=length_l+L_lc+1;
        }
        if(root->right!=NULL&&root->val==root->right->val){
            cnt=cnt+L_rc+1;
            length_r=length_r+L_rc+1;
        }
        L=max(length_l,length_r);
        return max(cnt,max(a,b));
    }
};
