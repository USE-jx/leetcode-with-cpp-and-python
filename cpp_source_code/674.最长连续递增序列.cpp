/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
             dp[i] = dp[i-1] + 1;
            if (ans < dp[i]) ans = dp[i];
        }
        return ans;

        
    }
};
// @lc code=end

