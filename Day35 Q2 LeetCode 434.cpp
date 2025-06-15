// Number of Segments in a String (#434)

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int n = s.length();

        // Traverse through the string character by character
        for (int i = 0; i < n; ++i) {
            // Check if the current character is not a space
            // and either it's the first character or the previous one was a space
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                count++; // Start of a new segment
            }
        }
        return count;
    }
};