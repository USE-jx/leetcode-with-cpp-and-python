// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem494.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * @brief 
 * 正数和x，负数和sum - x，
 * x - (sum - x) = target
 * x = (sum + target) / 2
 * 转换成了装满x容量的背包有多少种方法的问题
 * 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if ((sum + target) % 2 == 1) return 0;
        if (sum < abs(target)) return 0;

        int bag_size = (sum + target) / 2;
        vector<int> dp(bag_size+1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = bag_size; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag_size];
    }
};
// @lc code=end

