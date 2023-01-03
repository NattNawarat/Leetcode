# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mapList(self):
        # map node to node_map
        i = 1
        curr_node = self.head
        while(curr_node.next != None):
            self.node[i] = curr_node
            curr_node = curr_node.next
            i+=1
        self.node[i] = curr_node
    
    def reverseList(self,left,right):
        
        if(left == 1):
            # edge case if left == 1 don't forget to change head
            self.head = self.node[right]
        else:
            # change node[left-1] node.next to node[right]
            self.node[left-1].next = self.node[right]
        
        # change node[left].next to node[right].next
        self.node[left].next = self.node[right].next
        
        # reverse the interval
        for i in range(right,left,-1):
            self.node[i].next = self.node[i-1]
    
    def travelList(self):
        # map node to node_map
        i = 1
        curr_node = self.head
        while(curr_node.next != None):
            print(curr_node.val)
            curr_node = curr_node.next
            i+=1
        #print(curr_node.val)
    
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        self.head = head
        self.node = {}
        self.mapList()
        self.reverseList(left,right)
        self.travelList()
        return self.head