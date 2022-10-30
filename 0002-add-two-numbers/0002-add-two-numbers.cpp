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
        ListNode *output = new ListNode(0);
        ListNode *curr_node = output;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0){
            int a,b,sum;
            a = 0;
            b = 0;
            if(l1 != NULL){
                a = l1->val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                b = l2->val;
                l2 = l2 -> next;
            }
            sum = a + b + carry;
            if(sum >= 10) carry = 1;
            else carry = 0;
            sum = sum % 10;
            curr_node -> next = new ListNode(sum);
            curr_node = curr_node -> next;
        }
        return output->next;
    }
};