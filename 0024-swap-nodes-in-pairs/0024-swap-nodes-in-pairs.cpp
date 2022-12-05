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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        ListNode* curr_node = head;
        if(head->next != nullptr){
            head = head->next;
        }
        while (curr_node->next != nullptr) {
            ListNode *adj_node =curr_node->next,*next_node;
            //swap adj node first
            curr_node -> next = adj_node->next;
            adj_node -> next = curr_node;
            //check of curr_node->next is exist 
            if (curr_node->next != nullptr){
                next_node = curr_node->next;
                // if curr_node->next->next exist change curr_node->next to that
                if (curr_node->next->next != nullptr){
                    curr_node->next = curr_node->next->next;
                }
            }
            
            curr_node = next_node;
        }
        return head;
    }
};