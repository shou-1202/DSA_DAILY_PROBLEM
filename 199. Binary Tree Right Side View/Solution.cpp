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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        if(!root)return res;
        if(!root->left && !root->right){
            res.push_back(root->val);
            return res;
        }
        q.push(root);
        q.push(NULL);
        TreeNode* curr = root;
        while(q.size()!=1){
            curr = q.front();
            q.pop();
            if(q.front()==NULL){
                res.push_back(curr->val);
            }
            if(curr == NULL){
                q.push(NULL);
            }
            if(curr && curr->left){
                q.push(curr->left);
            }
            if(curr && curr->right){
                q.push(curr->right);
            }
        }
        return res;
    }
};