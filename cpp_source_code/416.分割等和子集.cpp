/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector> 
using namespace std;

/**
 * 本题可以转换成01背包，物品的重量和价值是相同的，需要把
 * 给的物体总重量找到总重量一半的物品放入背包
 * 如果总重量是奇数那肯定就找不到了
 * 看能装一半总重量的背包能否正好找到一半重量的物品放进去
 * 
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;
        int target = sum / 2;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]]+ nums[i]);
            }
        }
        if (dp[target] == target) return true;
        else return false;
    }
};
// @lc code=end

