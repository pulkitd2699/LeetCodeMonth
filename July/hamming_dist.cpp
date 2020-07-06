// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, calculate the Hamming distance.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        for(int i=0;i<32;i++){
            int a = x&(1<<i);
            int b = y&(1<<i);
            if(a!=b) cnt++;
        }
        return cnt;
    }
};