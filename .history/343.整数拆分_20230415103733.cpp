/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <vector>
// #include <cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < 1 / 2; ++j) {
                dp[i] = max(dp[i-1], max((i - j) * j, dp[]))
            }
        }
    }
};
// @lc code=end

