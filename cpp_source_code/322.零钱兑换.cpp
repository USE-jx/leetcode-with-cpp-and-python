/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 完全背包
 * dp[j]:凑够amount为j的最少硬币个数
 * 递推公式：dp[j] = min(dp[j-conis[i]]+1, dp[j])
 * 初始化：dp[0] = 0;
 * 遍历顺序：跟顺序无关，所以是求组合，外层遍历物品，内层遍历背包
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j-coins[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
// @lc code=end

