//if-else spam, lol
// There is a better methd, we'll see.

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> new_board = board;
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                int count = 0;
                if(i + 1 <= board.size() - 1){
                    if(board[i+1][j] == 1) count++;
                    if(j + 1 <= board[0].size() - 1)
                        if(board[i+1][j+1] == 1) count++;
                    if(j - 1 >= 0)
                        if(board[i+1][j-1] == 1) count++;
                }
                if(i - 1 >= 0){
                    if(board[i-1][j] == 1) count++;
                    if(j + 1 <= board[0].size() - 1)
                        if(board[i-1][j+1] == 1) count++;
                    if(j - 1 >= 0)
                        if(board[i-1][j-1] == 1) count++;
                }
                if(j + 1 <= board[0].size() - 1)
                    if(board[i][j+1] == 1) count++;
                if(j - 1 >= 0)
                    if(board[i][j-1] == 1) count++;
                
                if(board[i][j] == 1){
                    if(count > 3 || count < 2) new_board[i][j] = 0;
                    else if(count == 3 || count == 2) new_board[i][j] == 1;
                }
                else if(board[i][j] == 0 && count == 3) new_board[i][j] = 1;            
            }
        }
        
        board = new_board;
    }
};