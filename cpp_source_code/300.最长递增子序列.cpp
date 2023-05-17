/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * @brief 动态规划
 * dp[i]:nums第i个整数的最长递增子序列的长度
 * 递推公式：dp[i] = max(dp[i], dp[j]+1)
 * 初始化: dp[0]= 1
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        if (nums.size() <= 1) return nums.size();

        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if (ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};
// @lc code=end

