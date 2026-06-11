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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        
        ListNode* temp2 = head->next;
        while(temp!=NULL){
            int sum = 0;
            while(temp->val!=0){
                sum+=temp->val;
                temp = temp->next;
            }
            temp2->val = sum;
            temp = temp->next;
            temp2->next = temp;
            temp2 = temp2->next; 
        }
        return head->next;;
    }
};