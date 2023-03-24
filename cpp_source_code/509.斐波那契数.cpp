/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // if (n == 0) return 0;
        // if (n == 1) return 1;
        // //std::cout << "11";
        // return fib(n-1) + fib(n-2);
        if (n < 2) return n;
        //1 创建DP数组
        vector<int> dp(n+1);
        //2 确定递推公式
        //dp[i] = dp[i-1] + dp[i-2]
        //3 DP数组初始化
        dp[0] = 0;
        dp[1] = 1;
        //4 确定遍历顺序
        //从前向后
        //5 举例推导dp数组
        // 0 1 1 2 3 5
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

        
    }
};
// @lc code=end

