/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 本题可以转换成01背包问题，把给的一堆石头分成重量相同的两堆，如果能
 * 分成重量相同的两堆就对撞后就没有石头剩下了，返回0；如果不能分成两堆
 * 就返回重量的一堆减去重量小的一堆。
 * 求背包容量是一半重量时能不能装重量一半的石头
 * 
 */
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(3001, 0);

        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) {
            sum += stones[i];
        }
        int target = sum / 2;

        for (int i = 0; i < stones.size(); ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        
        return sum - dp[target] - dp[target];
    }
};
// @lc code=end

