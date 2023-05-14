/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 动态规划
 * dp[i]:包括第i间房在内能偷的最高金额
 * 递推公式：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
 * 初始化：dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
 * 遍历顺序：从前向后 
 * 
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end

