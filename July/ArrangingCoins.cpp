// You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins. Given n, find the total number of full staircase rows that can be formed. n is a non-negative integer and fits within the range of a 32-bit signed integer.

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2*long(n) + 0.25) - 0.5);
    }
};