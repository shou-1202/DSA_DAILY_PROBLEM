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
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next)return;
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int i = 0;
        temp = head;
        vector<ListNode* >p(count);
        while(i<count && temp!=NULL){
            p[i] = temp;
            temp = temp->next; i++;
        }
        int n = p.size();
        int low = 0, high = n-1;
        while(low+1!=high && low!=high){
            p[low]->next = p[high];
            p[high]->next = p[low+1];
            low++;high--;
        }
        p[high]->next = NULL;
    }
};