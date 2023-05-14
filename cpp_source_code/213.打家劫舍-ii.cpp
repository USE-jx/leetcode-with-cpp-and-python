// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * @brief 动态规划
 * 
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);

        //包含首，不包含尾
        for (int i = 2; i < nums.size()-1; ++i) {
            
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        //包含尾不包含首
        for (int i = 3; i < nums.size(); ++i) {
            
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return max(dp[nums.size()-2], dp2[nums.size() - 1]);
    }
};
// @lc code=end

