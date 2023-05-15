/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 动态规划
 * 最多完成两笔交易可以得到五个状态，
 * 不操作，一次买入，一次卖出，二次买入，二次卖出
 * dp[i][j]:第i天状态j所剩最大现金
 * 地推公式：
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])
 * dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i])
 * dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i])
 * dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i])
 * 
 * 初始化：
 * dp[0][0] = 0;
 * dp[0][1] = -prices[0];
 * dp[0][2] = 0;
 * dp[0][3] = -prices[0];
 * dp[0][4] = 0;
 * 遍历顺序：从前向后
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i]);
        }
        return dp[prices.size()-1][4];
    }
};
// @lc code=end

