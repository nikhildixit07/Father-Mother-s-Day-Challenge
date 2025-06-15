// Prime Number of Set Bits in Binary Representation (#762)

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;

        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num);
            if (primes.count(setBits)) {
                count++;
            }
        }
        return count;
    }
};