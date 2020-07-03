// There are 8 prison cells in a row, and each cell is either occupied or vacant.

// Each day, whether the cell is occupied or vacant changes according to the following rules:
// If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
// Otherwise, it becomes vacant.

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int x = N%14;
        if(x == 0) x = 14;
        string s;
        for(int i=0;i<8;i++){
            s += (cells[i] + '0');
        }
        for(int i=0;i<x;i++){
            string temp;
            temp += '0';
            for(int j=1;j<7;j++){
                temp += (s[j-1] == s[j+1])? '1' : '0';
            }
            temp += '0';
            s = temp;
        }
        vector<int> ans;
        for(int i=0;i<8;i++) ans.push_back(s[i] - '0');
        return ans;
    }
};