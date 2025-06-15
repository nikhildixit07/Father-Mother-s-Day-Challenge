# Plus One (#66)

class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        # Start from the last digit and move left
        for i in range(len(digits) - 1, -1, -1):
            # If the current digit is less than 9, just add 1 and return the result
            if digits[i] < 9:
                digits[i] += 1
                return digits
            # Otherwise, set the current digit to 0 and move to the next
            digits[i] = 0
        
        # If we reached here, that means all digits were 9 and we need to add an extra 1 at the front
        return [1] + digits