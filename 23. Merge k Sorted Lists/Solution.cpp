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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        if(lists.size() == 1)return lists[0];
        for(int i = 1; i<lists.size();i++){
            ListNode* sortedList = new ListNode();
            ListNode* curr = sortedList;
            ListNode* temp = lists[0];
            ListNode* temp2 = lists[i];
            if(!temp){
                lists[0] = lists[i];
            }
            while(temp!= NULL && temp2!=NULL){
                if(temp->val<=temp2->val){
                    curr->next = temp;
                    curr = temp;
                    temp = temp->next;
                }
                else{
                    curr->next = temp2;
                    curr = temp2;
                    temp2 = temp2->next;
                }
            }
            while(temp!=NULL){
                curr->next = temp;
                curr = temp;
                temp = temp->next;
            }
            while(temp2!=NULL){
                curr->next = temp2;
                curr = temp2;
                temp2 = temp2->next;
            }
            ListNode* dummy = sortedList;
            sortedList = sortedList->next;
            delete(dummy);
            lists[0] = sortedList;
        }
        return lists[0];
    }
};