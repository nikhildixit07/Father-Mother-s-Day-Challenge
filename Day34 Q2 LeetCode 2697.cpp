// Length of Last Word (#58)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int length = 0;
        bool counting = false;

        // Traverse string from end to start
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            } else if (counting) {
                // We've counted a word, and hit a space
                break;
            }
        }
        return length;
    }
};