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
private:
    int preIndex = 0;
    int postIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder) {
        // Create the root node from current preorder position
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // If the root's value doesn't match the current postorder value,
        // it means this root has a left child to be constructed.
        if (root->val != postorder[postIndex]) {
            root->left = build(preorder, postorder);
        }

        // If it still doesn't match, it has a right child to be constructed.
        if (root->val != postorder[postIndex]) {
            root->right = build(preorder, postorder);
        }

        // When root->val == postorder[postIndex], the subtree for this root is complete
        postIndex++;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, postorder);
    }
};