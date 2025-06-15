# Rotate List (#61)

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Edge case: empty list or no need to rotate
        if not head or not head.next or k == 0:
            return head
        
        # Step 1: Find the length of the list
        length = 0
        current = head
        while current:
            length += 1
            current = current.next
        
        # Step 2: Normalize k (same as original)
        k = k % length
        if k == 0:
            return head
        
        # Step 3: Traverse the list and find the new tail
        # (Iterating to the point where the rotation should happen)
        current = head
        for _ in range(length - k - 1):
            if current:  # Check if current is not None
                current = current.next
            else:
                break  # Avoid accessing .next if current is None
        
        # Ensure current is not None before accessing current.next
        if current and current.next:
            new_head = current.next
            current.next = None  # Cut the list at the new tail
        else:
            return None  # Return None if the list is malformed
        
        # Step 4: Traverse to the last node
        last_node = new_head
        while last_node and last_node.next:
            last_node = last_node.next
        
        # If last_node is not None, connect it to the original head
        if last_node:
            last_node.next = head
        
        return new_head