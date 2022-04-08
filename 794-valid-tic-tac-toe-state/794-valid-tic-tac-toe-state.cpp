// xxo
// xox
// oxo
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        auto [countX, count0] = getCount(board);
        if(countX - count0 > 1 || countX < count0) {
            return false;
        }
        bool isWinnerX = checkWinner(board, 'X');
        bool isWinnerY = checkWinner(board, 'O');
        if(isWinnerX && isWinnerY) {
            return false;
        }
        if(countX - count0 == 1 && isWinnerY) {
            return false;
        }
        if(countX == count0 && isWinnerX) {
            return false;
        }
        return true;
    }
    
    pair<int,int> getCount(vector<string>& board) {
        int first = 0, second = 0;
        for(string &row: board) {
            for(char &ch: row) {
                if(ch == 'X') {
                    first++;
                }
                else if(ch == 'O') {
                    second++;
                }
            }
        }
        return {first, second};
    }
    
    bool checkWinner(vector<string>& board, char character) {
        vector<int>rows(board.size()),cols(board[0].size());
        int diagnolCount = 0, antiDiagnolCount = 0;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == character) {
                    rows[i]++;
                    cols[j]++;
                    if(i == j) {
                        diagnolCount++;
                    }
                    if(i + j == cols.size()-1) {
                        antiDiagnolCount++;
                    }
                }
                if(rows[i] == rows.size() || cols[j] == cols.size()) {
                    return true;
                }
            }
        }
        return diagnolCount == cols.size() || antiDiagnolCount == cols.size();
    }
};