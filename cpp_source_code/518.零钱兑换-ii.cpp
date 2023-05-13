/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 完全背包
 * dp[j]:凑成amount为j的组合数，组合不强调顺序，排列强调顺序
 * 递推公式：dp[j] += dp[j-coin[i]];
 * 初始化：dp[0] = 1
 * 遍历顺序：外层物品，内层背包，这样计算的是组合数
 * 
 * 
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount+1,0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

