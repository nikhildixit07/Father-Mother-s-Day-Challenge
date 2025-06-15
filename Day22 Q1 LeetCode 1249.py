# Minimum Remove to Make Valid Parentheses (#1249)

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        stack = []

        # First pass: Remove extra ')'
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                if stack:
                    stack.pop()
                else:
                    s[i] = ''

        # Remove unmatched '('
        while stack:
            s[stack.pop()] = ''

        return ''.join(s)