/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, stack<TreeNode*>& s){
        if(!root)return;
        s.push(root);
        helper(root->left, s);
        helper(root->right, s);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        if(!root->left && !root->right)return;
        stack<TreeNode*>s;
        helper(root, s);

        while(s.size()>1){
            TreeNode* curr1 = s.top(); s.pop();
            TreeNode* curr2 = s.top(); s.pop();
            
            curr2->left = NULL;
            curr2->right = curr1;
            s.push(curr2);
        }
    }
};