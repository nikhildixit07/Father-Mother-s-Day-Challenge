// Lexicographically Smallest Palindrome (#2697)

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Use two-pointer approach to check and modify the string from both ends
        while (left < right) {
            // If characters don't match, replace the larger one with the smaller one
            if (s[left] != s[right]) {
                char smallerChar = min(s[left], s[right]);
                s[left] = s[right] = smallerChar;
            }
            left++;
            right--;
        }
        return s;
    }
};