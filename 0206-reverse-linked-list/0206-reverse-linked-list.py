# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self,node):
        if node is None:
            return node
        if node.next is None:
            return node
        newHead = self.reverse(node.next)
        node.next.next = node
        node.next = None
        return newHead
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.reverse(head)