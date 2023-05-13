/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief 完全背包
 * dp[j]: 整数为j的完全平方数的最少数量
 * 递推公式：dp[j] = min(dp[j],dp[j-i*i]+1)
 * 初始化：dp[0] = 0;
 * 遍历顺序：组合就行，先遍历物品，再遍历背包
 * 
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= sqrt(n); ++i ) {
            for (int j = 1; j <= n; ++j) {
                if (j >= i*i && dp[j - i*i] != INT_MAX) 
                dp[j] = min(dp[j],dp[j- i*i] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

