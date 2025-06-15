// Excel Sheet Column Title (#168)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-indexed
            int rem = columnNumber % 26;
            result = char('A' + rem) + result;
            columnNumber /= 26;
        }
        return result;
    }
};