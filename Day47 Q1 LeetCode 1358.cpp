// Number of Substrings Containing All Three Characters (#1358)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, n = s.length();
        vector<int> freq(3, 0);
        int left = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};