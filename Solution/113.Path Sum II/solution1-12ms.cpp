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
    vector<int> mystack;
    vector<vector<int>> mylist;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathsum(root,sum);
        return mylist;
    }
    void pathsum(TreeNode* root, int sum){
        if(root==NULL){
            return;
        }
        mystack.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&root->val==sum){
            mylist.push_back(mystack);
        }
        else{
            pathsum(root->left,sum-root->val);
            pathsum(root->right,sum-root->val);
        }
        mystack.pop_back();
    }
};
