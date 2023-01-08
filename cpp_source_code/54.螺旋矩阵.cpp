// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem54.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * 顺时针转圈取出每一个数并存入一维数组
 * 遍历矩阵行和列还是采用左闭右开
 *
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int m = matrix.size();    // 行数
        int n = matrix[0].size(); // 列数
        int size = m * n;
        vector<int> ans;
        int count = 0;
        int leftBound = 0;
        int rightBound = n - 1;
        int upBound = 0;
        int downBound = m - 1;
        while (size > 0)
        {
            // 左到右
            for (int cols = leftBound; cols <= rightBound && size > 0; ++cols)
            {
                ans.push_back(matrix[upBound][cols]);
                --size;
            }
            ++upBound;
            // 上到下
            for (int rows = upBound; rows <= downBound && size > 0; ++rows)
            {
                ans.push_back(matrix[rows][rightBound]);
                --size;
            }
            --rightBound;
            // 右到左
            for (int cols = rightBound; cols >= leftBound && size > 0; --cols)
            {
                ans.push_back(matrix[downBound][cols]);
                --size;
            }
            --downBound;
            // 下到上
            for (int rows = downBound; rows >= upBound && size > 0; --rows)
            {
                ans.push_back(matrix[rows][leftBound]);
                --size;
            }
            ++leftBound;
        }
        return ans;
    }
};
// @lc code=end
