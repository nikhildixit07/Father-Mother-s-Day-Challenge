// Reverse Vowels of a String (#345)

class Solution {
public:
    string reverseVowels(string s) {
        // Helper lambda to check if a character is a vowel (case insensitive)
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int left = 0;
        int right = s.length() - 1;

        // Use two-pointer approach to reverse vowels in-place
        while (left < right) {
            // Move left pointer until it points to a vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            // Move right pointer until it points to a vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};