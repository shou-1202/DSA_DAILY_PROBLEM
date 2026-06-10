class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& temp){
        if(!root)return;
        if(!root->left && !root->right){
            if(targetSum == root->val){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            return;
        }
        temp.push_back(root->val);
        int remaining = targetSum - root->val;
        helper(root->left, remaining, ans, temp);
        helper(root->right, remaining, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root, targetSum, ans, temp);
        return ans;
    }
};