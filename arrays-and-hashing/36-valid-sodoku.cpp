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
#include <algorithm>
#include <iterator>

using namespace std;

bool isValidSodoku(vector<vector<char>>& board) {
    int numberArray[9] = {0};
    int colNumberArray[9][9] = {0};
    int sectionNumberArray[3][9] = {0};
    // Iterate through all rows and check whether the configuration is valid
    for (int i = 0; i < 9; i++) {
        vector<char> row = board[i];
        // Check the section arrays
        if (i != 0 && i % 3 == 0) {
            for (int j = 0; j < 3; j++) {
                // cout << "Counting Sections: " << j << endl;
                for (int k = 0; k < 9; k++) {
                    int count = sectionNumberArray[j][k];
                    // cout << "Number: " << k << ", Count: " << count << endl;
                    if (count > 1) return false;
                }
            }
            // Clear the array and set to all 0
            memset(sectionNumberArray, 0, sizeof sectionNumberArray);
        }
        // Increment number array count
        for (int j = 0; j < 9; j++) {
            int columnSectionNumber = j / 3;
            char c = row[j];
            if (c != '.') {
                int num = c - '0';
                // cout << num << endl;
                numberArray[num]++;
                colNumberArray[j][num]++;
                sectionNumberArray[columnSectionNumber][num]++;
            }
        }
        // Check number array count for any values that are greater than 1
        for (int j = 0; j < 9; j++) {
            int count = numberArray[j];
            if (count > 1) return false;
        }
        // Reset the number array to contain all zeros
        memset(numberArray, 0, sizeof(numberArray[0]) * 9);
    }
    // Check whether columns are valid configurations
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int count = colNumberArray[i][j];
            if (count > 1) return false;
        }
    }
    // Check the very last section array
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 9; k++) {
            int count = sectionNumberArray[j][k];
            if (count > 1) return false;
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