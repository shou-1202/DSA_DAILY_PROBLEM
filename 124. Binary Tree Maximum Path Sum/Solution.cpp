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
    int helper(TreeNode* root, int& temp){
        if(!root)return 0;
        int leftMax = max(0, helper(root->left, temp));
        int rightMax = max(0, helper(root->right, temp));

        temp = max(temp, leftMax+root->val+rightMax);
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        int temp = INT_MIN;
        helper(root, temp);
        return temp;
        
    }
};