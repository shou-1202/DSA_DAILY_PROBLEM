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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 0;
        ListNode* temp1 = list1;
        while(count!=a-1){
            temp1 = temp1->next;
            count++;
        }
        ListNode* curr = temp1->next;count = a;
        temp1->next = list2;
        count = b-a + 1;
        while(count!=0){
            ListNode* dummy = curr;
            curr=curr->next;
            dummy->next = NULL;
            delete(dummy);
            count--;
        }
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next = curr;
        return list1;
    }
};