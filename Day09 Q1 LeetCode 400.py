# Nth Digit (#400)

class Solution:
    def findNthDigit(self, n: int) -> int:
        digit_length = 1
        count = 9
        start = 1
        
        while n > digit_length * count:
            n -= digit_length * count
            digit_length += 1
            count *= 10
            start *= 10
        
        num = start + (n - 1) // digit_length
        index = (n - 1) % digit_length
        # Get the digit at index from left (math way)
        for _ in range(digit_length - index - 1):
            num //= 10
        return num % 10