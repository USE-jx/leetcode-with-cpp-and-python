/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;

        for (int j = 0; j <= n; ++j) {
            for (int i = 1; i <= 2; ++i) {
                if (j >= i) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

