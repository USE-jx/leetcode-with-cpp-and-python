/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 动态规划
 * 分成四个状态：买入， 卖出， 今天卖出， 冷冻期
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            //买入可能前一天就是买入，可能今天买入昨天是卖出或冷冻期
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1]-prices[i], dp[i-1][3]-prices[i]));
            //卖出可能前一天是卖出，可能前一天是冷冻期
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            //今天卖出前一天只能是买入
            dp[i][2] = dp[i-1][0] + prices[i];
            //冷冻期前一天只能是今天卖出
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[prices.size()-1][3],max(dp[prices.size()-1][1], dp[prices.size()-1][2]));

    }
};
// @lc code=end

