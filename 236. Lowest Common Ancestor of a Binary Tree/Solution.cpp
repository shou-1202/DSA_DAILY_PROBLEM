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
        TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* left, TreeNode* right){
            if(!root)return NULL;

            left = helper(root->left, p, q, left, right);
            right = helper(root->right, p, q, left, right);
            if(root == p || root == q){
                return root;
            }
            else if(left && right){
                return root;
            }
            else if(left){
                return left;
            }
            else if(right){
                return right;
            }
            else{
                return NULL;
            }
        }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        TreeNode* left;
        TreeNode* right;
        return helper(root, p, q, left, right);
    }
};