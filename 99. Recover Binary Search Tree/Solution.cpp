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
    TreeNode* first = NULL;
    TreeNode* prev = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    void helper(TreeNode* root){
        if(!root)return;
        helper(root->left);
        if(prev != NULL && prev->val >root->val){
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        int temp;
        if(last!=NULL){
            temp = first->val;
            first->val =last->val;
            last->val = temp;
        }
        else if(first!=NULL && middle!=NULL){
            temp = first->val;
            first->val = middle->val;
            middle->val = temp;
        }
    }
};