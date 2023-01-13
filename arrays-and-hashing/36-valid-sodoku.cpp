/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

Constraints:
    board.length == 9
    board{i].length == 9
    board{i][j] is a digit 1-9 or '.'.
*/

#include <vector>
#include <iostream>

using namespace std;

bool isValidSodoku(vector<vector<char>>& board) {
    int cols[9][9] = { 0 };
    int rows[9][9] = { 0 };
    int squares[9][9] = { 0 };

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] != '.') {
                int num = board[r][c] - '0' - 1;
                int k = r / 3 * 3 + c / 3;
                if (cols[c][num] || rows[r][num] || squares[k][num]) 
                    return false;
                cols[c][num] = rows[r][num] = squares[k][num] = 1;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    vector<vector<char>> board = 
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};

    // vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    bool isValid = isValidSodoku(board);
    cout << isValid << endl;
    return 0;
}