// Partition List (#86)

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        std::vector<int> less, greaterOrEqual;
        ListNode* curr = head;

        // First pass: store values into two separate vectors
        while (curr) {
            if (curr->val < x)
                less.push_back(curr->val);
            else
                greaterOrEqual.push_back(curr->val);
            curr = curr->next;
        }

        // Combine both vectors into one list
        std::vector<int> combined = less;
        combined.insert(combined.end(), greaterOrEqual.begin(), greaterOrEqual.end());

        // Create a new linked list from combined vector
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for (int val : combined) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return dummy->next;
    }
};