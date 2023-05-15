// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem121.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 动态规划
 * dp[i][0]:第i天持有股票的最多现金
 * dp[i][1]:第i天不持有股票的最多现金
 * 递推公式：
 * dp[i][0] = max(dp[i-1][0], -prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i])
 * 初始化： 
 * dp[0][0] = -prices[0]
 * dp[0][1] = 0
 * 遍历循序：从前向后
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);

        }
        return dp[prices.size()-1][1];
    }
};
// @lc code=end

