# Swapping Nodes in a Linked List (#1721)
# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        # Find the length of the linked list
        length = 0
        current = head
        while current:
            length += 1
            current = current.next

        # Find the k-th node from the beginning
        first = head
        for _ in range(k - 1):
            first = first.next

        # Find the k-th node from the end
        second = head
        for _ in range(length - k):
            second = second.next

        # Swap their values
        first.val, second.val = second.val, first.val

        return head