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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        TreeNode* curr = root;
        q.push(curr);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            temp.push_back(curr->val);
            if(curr->left && !curr->right){
                q.push(curr->left);
            }
            else if(curr->left && curr->right){
                q.push(curr->left);
                q.push(curr->right);
            }
            else if(curr->right && !curr->left){
                q.push(curr->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};