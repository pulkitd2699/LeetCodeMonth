// Given an input string, reverse the string word by word.

class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream stream(s);
        string ans;
        stack<string> st;
        while(stream >> word) st.push(word);
        while(!st.empty()){
            ans = ans + st.top() + " ";
            st.pop();
        }
        return ans.substr(0,ans.size()-1);
    }
};