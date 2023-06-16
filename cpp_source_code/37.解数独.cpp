/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    
    bool backtracking(vector<vector<char>>& board) {
       for (int i = 0; i < 9; ++i) {
           for (int j = 0; j < 9; ++j) {
               if (board[i][j] == '.') {
                   for (int k = '1'; k <= '9'; ++k) {
                       if (is_valid(board, i, j, k)) {
                           board[i][j] = k;
                           if (backtracking(board)) return true;
                           board[i][j] = '.';
                       }
                   }
                   return false;
               }
           }
       } 
       return true;
    }
    bool is_valid(vector<vector<char>>& board, int row, int col, int val) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == val) {
                return false;
            }
        }
        int start_row = row / 3 * 3;
        int start_col = col / 3 * 3;
        for (int i = start_row; i < start_row + 3; ++i) {
            for (int j = start_col; j < start_col + 3; ++j) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

