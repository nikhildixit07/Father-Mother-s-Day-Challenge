// Delete Node in a Linked List (#237)

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Create a vector to store values of nodes from current to end
        std::vector<int> vals;
        ListNode* temp = node;
        while (temp != nullptr) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        // Overwrite current and following nodes with the next values
        temp = node;
        for (int i = 1; i < vals.size(); ++i) {
            temp->val = vals[i];
            if (i == vals.size() - 1) {
                // Last value: delete the last node
                ListNode* del = temp->next;
                temp->next = nullptr;
                delete del;
            } else {
                temp = temp->next;
            }
        }
    }
};