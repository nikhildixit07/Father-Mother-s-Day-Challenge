# Reverse Linked List (#206)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # Initialize pointers
        prev = None
        curr = head

        # Traverse the list
        while curr is not None:
            next_node = curr.next
            
            curr.next = prev 
        
            prev = curr 
            curr = next_node
        return prev