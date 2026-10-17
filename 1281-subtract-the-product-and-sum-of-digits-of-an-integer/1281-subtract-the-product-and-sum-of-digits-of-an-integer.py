class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        sum = 0
        prod = 1
        while n != 0:
            digit = n % 10
            sum += digit
            prod *= digit
            n //= 10
        return prod - sum
