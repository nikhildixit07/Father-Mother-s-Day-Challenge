// Move Zeroes (#283)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[insertPos++] = nums[i];
            }
        }

        // Fill the rest with zeroes
        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }
};