/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * 转圈把2维n*n数组填满，从1开始，最后是n方
 * 每转一圈需要四次循环，遵循统一的左闭右开不容易乱
 * 需要大循环n/2次，如果n是奇数，那最后剩中间的元素需要填一下
 * 每次转一圈需要更新起始位置和小循环次数
 *
 */
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0)); // 定义一个二维数组
        int startX = 0, startY = 0;                    // 起始位置
        int value = 1;                                 // 元素值从一开始
        int times = n / 2;                             // 大循环次数
        int cols = 0, rows = 0;                        // 列数和行数
        int shrink = 1;                                // 右边界收缩
        while (times--)
        {
            // 每一次从新的起始位置开始循环
            rows = startX;
            cols = startY;

            // 左到右
            for (; cols < n - shrink; ++cols)
            {
                ans[rows][cols] = value++;
            }
            // 上到下
            for (; rows < n - shrink; ++rows)
            {
                ans[rows][cols] = value++;
            }
            // 右到左
            for (; cols > startY; --cols)
            {
                ans[rows][cols] = value++;
            }
            // 下到上
            for (; rows > startX; --rows)
            {
                ans[rows][cols] = value++;
            }
            ++startX;
            ++startY;
            ++shrink;
        }
        // 如果是奇数，把中间补上
        if (n % 2 == 1)
        {
            ans[startX][startY] = n * n;
        }

        return ans;
    }
};
// @lc code=end
