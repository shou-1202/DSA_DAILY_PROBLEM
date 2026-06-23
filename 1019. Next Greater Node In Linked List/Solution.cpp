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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int size=0;
        ListNode* curr = head;
        while(curr!=NULL){
            size++;
            curr = curr->next;
        }
        vector<int>ans(size, 0);
        if(!head->next){
            return ans;
        }
        stack<pair<int, int>>s;
        ListNode*temp = head;
        int i = -1;
        while(temp!=NULL){
            i++;
            while(!s.empty() && s.top().second < temp->val){
                ans[s.top().first] = temp->val;
                s.pop();
            }
            s.push({i, temp->val});
            temp = temp->next;
        }
        return ans;

    }
};