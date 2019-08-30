class Solution {
//https://leetcode.com/problems/word-search/
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(word[0] == board[i][j]){ 
                    if (look(board, i, j, word, 0, visited)) return true;
                }
            }
        }

        return false;
    }

    /*
          1
        4   2
          3
    */

    bool look(vector<vector<char>>& board, int i, int j, string word, int c, vector<vector<bool>>& visited) {
        if (word[c] != board[i][j] || visited[i][j]) return false;
        visited[i][j] = true;
        if (c == word.size()-1) return true;

        if (i+1 < board.size()) {
            if (look(board,i+1,j,word,c+1,visited)) return true;
        }
        if (j+1 < board[0].size()) {
            if (look(board,i,j+1,word,c+1,visited)) return true;
        }
        if (i-1 >= 0) {
            if (look(board,i-1,j,word,c+1,visited)) return true;
        }
        if (j-1 >= 0) {
            if (look(board,i,j-1,word,c+1,visited)) return true;
        }

        visited[i][j] = false;
        return false;
    }
};
