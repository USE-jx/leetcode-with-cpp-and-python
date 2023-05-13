/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 完全背包求排列
 * d[j]:目标为j的排列个数
 * 递推公式：dp[j] += dp[j - nums[i]]
 * 初始化：dp[0] = 1;
 * 遍历顺序：先背包再物品
 * 
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                if ((j - nums[i]) >= 0 && dp[j] < INT_MAX - dp[j - nums[i]])
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end

