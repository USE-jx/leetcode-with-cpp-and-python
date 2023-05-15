/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1,0));
        for (int i = 1; i < 2*k+1; i += 2) {
            dp[0][i] = -prices[0];
        }
        
        
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j < 2*k+1; j += 2) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
            }
            for (int j = 2; j <= 2*k; j += 2) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }
};
// @lc code=end

