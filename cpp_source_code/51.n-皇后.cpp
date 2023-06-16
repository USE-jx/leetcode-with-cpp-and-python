/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<string>> result;

    void backtracking(int n, int row, vector<string> &chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (is_valid(chessboard, n, row, col)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    bool is_valid(vector<string> &chessboard, int n, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row-1, j = col-1; i >=0 && j >=0; --i, --j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }            
        }
        return true;
    } 

    
    vector<vector<string>> solveNQueens(int n) {

        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};
// @lc code=end

