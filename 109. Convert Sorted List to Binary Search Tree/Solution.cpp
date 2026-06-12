/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(TreeNode* root, ListNode* head){
        if(!head)return NULL;
        if(!head->next){
            TreeNode* Node = new TreeNode(head->val);
            return Node;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = slow;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            temp = slow;
            slow = slow->next;
        }
        if(temp->next){
            temp->next = NULL;
        }
        TreeNode* Node = new TreeNode(slow->val);
        root = Node;

        root->left = helper(root->left, head);
        root->right = helper(root->right, slow->next);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = new TreeNode();
        return helper(root, head);
    }
};