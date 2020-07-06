// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int c=0,pos;
        for(int i=n-1;i>=0;i--){
            if(digits[i] == 9 and i==0){
                ans.insert(ans.begin(),0);
                ans.insert(ans.begin(),1);
            }
            else if(digits[i] == 9 and i==n-1){
                 ans.insert(ans.begin(), 0);
                 c=1;
            }
            else if(c==1){
                if(digits[i] != 9){
                    ans.insert(ans.begin(), digits[i]+1);
                    pos = i-1;
                    break;
                }
                else{
                    ans.insert(ans.begin(), 0);
                }
            }
            else{
                ans.insert(ans.begin(), digits[i]+1);
                pos = i-1;
                break;
            }
        }
        for(int i=pos;i>=0;i--) ans.insert(ans.begin(), digits[i]);
        return ans;
    }

int main() {
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    vector<int> ans = plusOne(digits);
    for(auto it : ans) cout << it << " "; 
}