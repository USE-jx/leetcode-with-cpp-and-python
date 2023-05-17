/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * @brief 动态规划
 * dp[i][j]:第i天j状态下持有的最大现金 j是买入和卖出两种状态
 * 递推公式：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
 * 
 * 初始化
 * dp[0][0] = -prices[0];
 * dp[0][1] = 0;
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));

        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end

