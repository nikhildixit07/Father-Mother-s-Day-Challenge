# Palindrome Number (#9)

class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Edge cases: negative numbers and numbers ending with 0 (but not 0 itself)
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reversed_half = 0
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10

        # For odd-digit numbers, reversed_half//10 removes the middle digit
        return x == reversed_half or x == reversed_half // 10