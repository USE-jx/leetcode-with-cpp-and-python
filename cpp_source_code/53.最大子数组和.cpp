/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 动态规划
 * dp[i]: 包括下标i 的连续数组最大和
 * 递推公式：dp[i] = max(dp[i-1] + nums[i], nums[i]);
 * 初始化：dp[0] = nums[0];
 * 遍历顺序：从前向后
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if (ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};
// @lc code=end

