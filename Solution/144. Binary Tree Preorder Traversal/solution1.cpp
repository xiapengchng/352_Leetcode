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
    vector<int> preorderTraversal(TreeNode* root) { //时间复杂度o(n)，空间复杂度o(n)
        stack<TreeNode*> s;
        vector<int> v;
        
        if(root != nullptr) s.push(root);
        
        while(!s.empty()){
            
            TreeNode* p = s.top(); //这里不能直接将s.pop()赋值给p，因为这里s.pop()返回void
            s.pop();
            v.push_back(p->val);
            
            if(p->right != nullptr) s.push(p->right);
            if(p->left != nullptr) s.push(p->left);
            
        }
        return v;

    }
};



