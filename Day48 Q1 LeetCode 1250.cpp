// Check If It Is a Good Array (#1250)

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    bool isGoodArray(vector<int>& nums) {
        int currentGCD = 0;
        for (auto num : nums) {
            currentGCD = gcd(currentGCD, num);
        }
        return currentGCD == 1;
    }
};