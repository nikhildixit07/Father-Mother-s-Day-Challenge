// Find First Palindromic String in the Array (#2108)

public class Solution {
    public String firstPalindrome(String[] words) {
        for (String word : words) {
            if (isPalindrome(word)) {  // Check if the word is a palindrome
                return word; 
            }
        }
        return "";  // No palindrome, return empty string
    }
    
    // Helper function to check if a string is palindrome
    private boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;  // Not palindrome if mismatch found
            }
            left++;
            right--;
        }
        return true;
    }
}