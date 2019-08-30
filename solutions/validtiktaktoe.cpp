class Solution {
//https://leetcode.com/problems/valid-tic-tac-toe-state/
public:
    bool validTicTacToe(vector<string>& board) {
        /*
            If there are more Os than Xs return 0
            If there are 3Xs and same Os return 0
            If there are 3Os and more Xs return 0
            else return 1
        
        */
        int Os = 0;
        int Xs = 0;       
        for(auto x : board){
            for(auto y : x){
                if(y == 'O')Os++;
                if(y == 'X')Xs++;
            }
        }
        if(Os > Xs){
            return false;
        }
        
        if(Xs - Os != 1 && Xs - Os != 0){
            return false;
        }
        
        bool t3Xs = false;
        bool t3Os = false;
        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
            t3Xs = true;
        }
        if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
            t3Xs = true;
        }
        if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
            t3Xs = true;
        } 
        if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
            t3Xs = true;
        }
        if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
            t3Xs = true;
        }
        if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
            t3Xs = true;
        }
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
            t3Xs = true;
        }
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
            t3Xs = true;
        }
        
        if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
            t3Os = true;
        }
        if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
            t3Os = true;
        }
        if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
            t3Os = true;
        } 
        if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
            t3Os = true;
        }
        if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
            t3Os = true;
        }
        if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
            t3Os = true;
        }
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
            t3Os = true;
        }
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
            t3Os = true;
        }
        
        if(t3Xs && Xs <= Os){
            return false;
        }
        if(t3Os && Xs > Os){

            return false;
        }
         return true;
    }
        
};
