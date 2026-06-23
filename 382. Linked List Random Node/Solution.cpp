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
    int size = 0;
    ListNode* curr = new ListNode();
    Solution(ListNode* head) {
        curr= head;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int small = 1;
        int large = size;

        int num = rand()%(large-small+1) + small;
        ListNode* temp = this->curr;
        while(num!=1){
            num--;
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */