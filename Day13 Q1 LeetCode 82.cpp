// Remove Duplicates from Sorted List II (#82)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        std::map<int, int> freq;
        ListNode* curr = head;

        // First pass: count frequency of each value
        while (curr) {
            freq[curr->val]++;
            curr = curr->next;
        }

        // Second pass: rebuild list using only unique values
        ListNode dummy(0);
        ListNode* tail = &dummy;
        curr = head;

        while (curr) {
            if (freq[curr->val] == 1) {
                tail->next = new ListNode(curr->val);
                tail = tail->next;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};