// Find Greatest Common Divisor of Array (#1979)

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        return __gcd(mini, maxi); // built-in GCD function
    }
};