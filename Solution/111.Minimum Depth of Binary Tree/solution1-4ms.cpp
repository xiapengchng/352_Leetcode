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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int n1,n2;
        n1=minDepth(root->left);
        n2=minDepth(root->right);
        if(n1==0)
            return n2+1;
        if(n2==0)
            return n1+1;
        return min(n1,n2)+1;
    }
};
