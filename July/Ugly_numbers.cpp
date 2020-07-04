// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 


// Time Inefficient | O(1) space
// class Solution {
// public:
    
//     int maxDivide(int a, int b){
//         while(a%b == 0)
//             a /= b;
//         return a;
//     }
    
//     int isUgly(int num){
//         num = maxDivide(num,2);
//         num = maxDivide(num,3);
//         num = maxDivide(num,5);
        
//         return (num == 1)? 1 : 0;
//     }
    
//     int nthUglyNumber(int n) {
//         int i=1;
//         int count = 1;
//         while(n>count){
//             i++;
//             if(isUgly(i)) count++;
//         }
//         return i;
//     }
// };

// O(n) time | O(n) space | Dynamic Programming
class Solution {
public:
    int nthUglyNumber(int n) {
        long ugly[1700];
        long i2 = 1, i3=1, i5=1;
        ugly[1] = 1;
        long nxt2 = 2, nxt3 = 3, nxt5 = 5;
        long nxt_ugly = 1;
        for(int i=2;i<1700;i++){
            nxt_ugly = min(min(nxt2,nxt3),nxt5);
            ugly[i] = nxt_ugly;
            if(nxt_ugly == nxt2){
                i2++;
                nxt2 = ugly[i2]*2;
            }
            if(nxt_ugly == nxt3){
                i3++;
                nxt3 = ugly[i3]*3;
            }
            if(nxt_ugly == nxt5){
                i5++;
                nxt5 = ugly[i5]*5;
            }
        }
        return ugly[n];
    }
};