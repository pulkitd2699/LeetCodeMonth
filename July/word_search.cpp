// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

class Solution {
public:
    bool findMatch(vector<vector<char>>& board, string word, int x, int y, int n, int m, int pos){
        int l = word.size();
        if(pos == l) return true;
        if(x < 0 or x >= n or y < 0 or y >= m) return false;
        
        if(board[x][y] == word[pos]){
            char temp = board[x][y];
            board[x][y] = '#';
            
            bool res = findMatch(board, word, x+1, y, n, m, pos+1) or
                        findMatch(board, word, x, y+1, n, m, pos+1) or
                        findMatch(board, word, x-1, y, n, m, pos+1) or
                        findMatch(board, word, x, y-1, n, m, pos+1);
            
            board[x][y] = temp;
            return res;
        }   
        else return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int l = word.size();
        int n = board.size();
        int m = board[0].size();
        if(l > n*m) return false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(findMatch(board, word, i, j, n, m, 0)) return true;
                }
            }
        }
        return false;
    }
};