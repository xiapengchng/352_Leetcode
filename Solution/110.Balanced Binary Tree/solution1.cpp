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
    bool isBalanced(TreeNode* root) {
        int a;
        return f(root,a);
    }
    bool f(TreeNode* root,int & height){
        if(root==NULL){
            height=-1;
            return true;
        }
        int h1,h2;
        bool b1,b2;
        b1=f(root->left,h1);
        b2=f(root->right,h2);
        height=max(h1,h2)+1;
        return b1&&b2&&fabs(h1-h2)<=1;
    }
};
