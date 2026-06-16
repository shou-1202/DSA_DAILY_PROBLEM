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
    bool validate(TreeNode* node, long long min_boundary, long long max_boundary) {
        if (node == nullptr) return true;
        
        if (node->val <= min_boundary || node->val >= max_boundary) {
            return false;
        }
        
        return validate(node->left, min_boundary, node->val) && 
               validate(node->right, node->val, max_boundary);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }  
};