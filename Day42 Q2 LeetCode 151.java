// Reverse Words in a String (#151)

class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split("\\s+");
        
        // Use two pointers to reverse the words array
        int left = 0, right = words.length - 1;
        while (left < right) {
            String temp = words[left];
            words[left] = words[right];
            words[right] = temp;
            left++;
            right--;
        }
        return String.join(" ", words);
    }
}