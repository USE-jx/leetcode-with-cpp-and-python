/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * 大循环次数为二维数组的元素个数，每次行列小循环都要size--
 * 用上下左右边界作为小循环条件，每次行列循环一次都要更新边界值
 * 
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //行数
        int n = matrix[0].size(); //列数
        int size = m * n; //二维矩阵元素个数
        int upBound = 0;
        int downBound = m - 1;
        int leftBound = 0;
        int rightBound = n - 1;
        vector<int> ans;
        while (size > 0) {

            //左到右
            for (int cols = leftBound; cols <= rightBound && size > 0; ++cols) {
                ans.push_back(matrix[upBound][cols]);
                --size;
            }
            ++upBound;
            //上到下
            for (int rows = upBound; rows <= downBound && size >  0; ++rows) {
                ans.push_back(matrix[rows][rightBound]);
                --size;
            }
            --rightBound;
            //右到左
            for (int cols = rightBound; cols >= leftBound && size > 0; --cols) {
                ans.push_back(matrix[downBound][cols]);
                --size;
            }
            --downBound;
            //下到上
            for (int rows = downBound; rows >= upBound && size > 0; --rows) {
                ans.push_back(matrix[rows][leftBound]);
                --size;
            }
            ++leftBound;
        }
        return ans;
    }
};
// @lc code=end

