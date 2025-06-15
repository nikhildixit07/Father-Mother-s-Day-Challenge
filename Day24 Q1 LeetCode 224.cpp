// Basic Calculator (#224)

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;   // To store results
        stack<int> ops;    // To store signs
        int result = 0;
        int sign = 1;
        int i = 0;

        while (i < s.length()) {
            char ch = s[i];

            if (isdigit(ch)) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += num * sign;
                continue; 
            }
            else if (ch == '+') {
                sign = 1;
            }
            else if (ch == '-') {
                sign = -1;
            }
            else if (ch == '(') {
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                result = nums.top() + ops.top() * result;
                nums.pop();
                ops.pop();
            }
           
            i++;
        }

        return result;
    }
};