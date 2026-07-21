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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        int carry = 0;
        if(!l1->next && !l2->next){
            int a = l1->val + l2->val;
            carry = a/10;
            if(carry==0){
                l3->val = a;
            }
            else{
                ListNode* temp = l3;
                ListNode* newNode = new ListNode();
                temp->val = carry;
                newNode->val = a%10;
                temp->next = newNode;
            }
            return l3;
        }

        stack<int>s1;
        stack<int>s2;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while(temp1!=NULL){
            s1.push(temp1->val);
            temp1 = temp1->next;
        }

        while(temp2!=NULL){
            s2.push(temp2->val);
            temp2=temp2->next;
        }
        ListNode* temp3 = NULL;
        while(!s1.empty()&& !s2.empty()){
            int a = s1.top() + s2.top() + carry;
            s1.pop();s2.pop();

            carry = a/10;
            ListNode* newNode = new ListNode();
            newNode->val = a%10;

            newNode->next = temp3;
            temp3 = newNode;
        }

        while(!s1.empty()){
            int a = s1.top()+carry;
            s1.pop();

            carry = a/10;
            ListNode* newNode = new ListNode();
            newNode->val = a%10;

            newNode->next = temp3;
            temp3 = newNode;
        }

        while(!s2.empty()){
            int a = s2.top()+carry;
            s2.pop();

            carry = a/10;
            ListNode* newNode = new ListNode();
            newNode->val = a%10;

            newNode->next = temp3;
            temp3 = newNode;
        }

        if(carry!=0){
            ListNode* newNode = new ListNode();
            newNode->val = carry;

            newNode->next = temp3;
            temp3 = newNode;
        }

        l3->next = temp3;
        temp3 = l3;
        l3 = l3->next;
        delete(temp3);

        return l3;
    }
};