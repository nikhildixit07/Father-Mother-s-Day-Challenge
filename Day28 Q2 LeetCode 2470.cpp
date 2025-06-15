// Number of Subarrays With LCM Equal to K (#2470)

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int lcm = nums[i];

            // Skip elements that can't divide k
            if (k % nums[i] != 0) continue;

            for (int j = i; j < n; ++j) {
                // Compute LCM of the current subarray
                lcm = lcm * nums[j] / gcd(lcm, nums[j]);

                // If LCM exceeds k, break early
                if (lcm > k) break;

                // If LCM equals k, increment count
                if (lcm == k) ++count;
            }
        }

        return count;
    }

private:
    // Utility to compute GCD
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};