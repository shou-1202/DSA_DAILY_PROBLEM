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
    int getHeight(TreeNode* root){
        if(!root)return 0;
        return 1+(max(getHeight(root->left),  getHeight(root->right)));
    }
    TreeNode* getlevelNodes(TreeNode* root, int level){
        if(!root)return NULL;
        if(level==1){
            return root;
        }
        else if(level>1){
            TreeNode* one = getlevelNodes(root->left, level-1);
            if(one)return one;
            else{
                TreeNode* two = getlevelNodes(root->right, level-1);
                if(two)return two;
            }
        }
        return NULL;
    }
    int findBottomLeftValue(TreeNode* root) {
        int height = getHeight(root);
        TreeNode* temp = getlevelNodes(root, height);

        return temp->val;
    }
};