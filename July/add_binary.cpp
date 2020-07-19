// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

class Solution {
public:
    string addBinary(string a, string b) {
        int p = a.size();
        int q = b.size();
        string ans = "";
        char carry = '0';
        while(p>0 and q>0){
            int ones=0;
            if(carry == '1') ones++;
            if(a[p-1] == '1') ones++;
            if(b[q-1] == '1') ones++;
            if(ones == 0){
                ans += '0';
                carry = '0';
            }
            else if(ones==1){
                ans += '1';
                carry = '0';
            }
            else if(ones == 2){
                ans += '0';
                carry = '1';
            }
            else if(ones == 3){
                ans += '1';
                carry = '1';
            }
            p--; q--;
        }
        string big = (p > q) ? a : b;
        int ind = abs(p-q) - 1;
        if(ind == -1){
            if(carry == '1') ans += '1';
            reverse(ans.begin(), ans.end());
            return ans;
        }
        for(int i=ind;i>0;i--){
            int ones=0;
            if(carry == '1') ones++;
            if(big[i] == '1') ones++;
            
            if(ones == 0){
                ans += '0';
                carry = '0';
            }
            else if(ones==1){
                ans += '1';
                carry = '0';
            }
            else if(ones == 2){
                ans += '0';
                carry = '1';
            }
            else if(ones == 3){
                ans += '1';
                carry = '1';
            }
        }

        if(big[0] != carry) ans += '1';
        else if(big[0] == carry and big[0] == '1') ans += "01";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};