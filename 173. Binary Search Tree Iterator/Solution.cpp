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
class BSTIterator {
public:
    TreeNode* curr = new TreeNode();
    vector<int> result;
    int i = 0;
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        curr = root;
        
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
    }
    
    int next() {
        int ans = this->result[i];
        i++;
        return ans;

    }
    
    bool hasNext() {
        if(i==this->result.size())return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */