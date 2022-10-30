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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* currNode =  head;
        ListNode* delNode =  head;
        while(currNode -> next != nullptr){
            currNode = currNode->next;
            if(i >= n){
               delNode = delNode->next; 
            }
            
            i++;
        }
    //printf("%d %d\n",currNode->val,delNode->val);
    if(i == 0 ){
        head = nullptr;
    }
    else if(i == n-1 ){
        head = head -> next;
    }
    else{
        delNode -> next= (delNode -> next) -> next;
    }
    return head;
    }
};