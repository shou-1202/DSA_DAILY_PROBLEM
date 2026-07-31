#include <string>
#include <queue>
#include <sstream>

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Mark empty branches with "N"
            if (curr == NULL) {
                ans += "N ";
            } else {
                // Store the value and push children
                ans += to_string(curr->val) + " ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        // Use stringstream to read word-by-word
        stringstream ss(data);
        string str;
        
        // Parse the root
        getline(ss, str, ' ');
        TreeNode* root = new TreeNode(stoi(str));
        
        // Queue to track parent nodes that need children attached
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Read and attach the left child
            if (getline(ss, str, ' ')) {
                if (str != "N") {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    curr->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            // Read and attach the right child
            if (getline(ss, str, ' ')) {
                if (str != "N") {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    curr->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));