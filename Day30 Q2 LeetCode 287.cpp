// Find the Duplicate Number (#287)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detect cycle
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];           // Move one step
            fast = nums[nums[fast]];     // Move two steps
        } while (slow != fast);
        // Phase 2: Find the start of the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; // or fast, both point to the duplicate
    }
};