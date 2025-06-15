// Maximum Number of Vowels in a Substring of Given Length (#1456)

class Solution {
    public int maxVowels(String s, int k) {
        int maxCount = 0;
        int currentCount = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                currentCount++;
            }
        }
        maxCount = currentCount;
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                currentCount++;
            }
            if (isVowel(s.charAt(i - k))) {
                currentCount--;
            }
            maxCount = Math.max(maxCount, currentCount);
        }
        return maxCount;
    }
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}