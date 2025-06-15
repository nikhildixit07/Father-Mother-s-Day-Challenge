// Valid Parenthesis String (#678)

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;     // treat '*' as ')'
                high++;    // treat '*' as '('
            }
            if (high < 0) return false;  // too many ')'
            if (low < 0) low = 0;        // '*' saved us
        }
        return low == 0;
    }
};