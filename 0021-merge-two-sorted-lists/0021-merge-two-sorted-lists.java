/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode mergedList = null;
        ListNode currNode = null;
        while(list1 != null && list2 != null){
            ListNode appendList = null;
            if(list1.val <= list2.val){
                appendList = list1;
                list1 = list1.next;
            } else {
                appendList = list2;
                list2 = list2.next;
            }
            appendList.next = null;
            if(mergedList == null){
                mergedList = appendList;
                currNode = mergedList;
            } else {
                currNode.next = appendList;
                currNode = currNode.next;
            }
        }
        if(list1 != null){
            if(mergedList == null){
                mergedList = list1;
            } else {
                currNode.next = list1;
            }
        } else if (list2 != null){
            if(mergedList == null){
                mergedList = list2;
            } else {
                currNode.next = list2;
            }
        }
        return mergedList;
    }
}