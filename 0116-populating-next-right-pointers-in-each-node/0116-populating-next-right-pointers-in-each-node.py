"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root == None:
            return root
        queue = deque()
        next_node = {}
        queue.append((root,0))
        while queue:
            # get curr_node and level
            curr_node , curr_level = queue.popleft()
            #print(curr_node,curr_level)
            # assign curr_node.next and update next_node on each level
            if curr_level in next_node.keys():
                curr_node.next = next_node[curr_level]
            else :
                curr_node.next = None
            #print(curr_node.next)
            next_node[curr_level] = curr_node
            if curr_node.right != None:
                queue.append((curr_node.right,curr_level+1))
                queue.append((curr_node.left,curr_level+1))
        return root
            