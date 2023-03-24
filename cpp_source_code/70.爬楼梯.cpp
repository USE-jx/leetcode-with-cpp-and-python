// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;
        // 创建DP数组
        vector<int> dp(n + 1);
        // 确定递推公式
        // dp[i] = dp[i-1] + dp[i-2]
        // 递推初始化
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << "dp[i]:" << dp[i] << endl;
        }
        return dp[n];
    }
};
// @lc code=end
