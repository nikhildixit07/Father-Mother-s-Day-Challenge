// Remove Nth Node From End of List (#19)

Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        // First pass: find the total length
        while (temp) {
            len++;
            temp = temp->next;
        }

        // If we're deleting the first node
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Second pass: stop at the node before the one to remove
        temp = head;
        for (int i = 1; i < len - n; ++i) {
            temp = temp->next;
        }

        // Delete the target node
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};