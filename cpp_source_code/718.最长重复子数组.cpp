/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <vector>
using namespace std;
/**
 * @brief 动态规划
 * dp[i][j]:i-1为结尾的nums1和j-1结尾的nums2的最长公共数组
 * 递推公式：if nums1[i-1] = nums2[j-1] 
 * dp[i][j] = dp[i-1][j-1] + 1
 * 初始化：dp[i][0] dp[0][j] = 0
 * 
 */
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));

        int ans = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {

                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if (ans < dp[i][j]) ans = dp[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

