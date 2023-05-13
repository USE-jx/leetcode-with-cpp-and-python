// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem474.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
/**
 * @brief 
 * dp[i][j]: 最多有i个0，j个1的最大子集个数
 * 递推公式： dp[i][j] = max(dp[i][j],dp[i-zeronum][j-onenum]+1);
 * 初始化：0
 * 遍历顺序：背包容量从后往前
 * 
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        
        //遍历物品
        for (string str : strs) {
            
            int zero_num = 0, one_num = 0;
            for (char c : str) {
                if (c == '0') {
                    ++zero_num;
                } else {
                    ++one_num;
                }
            }

            //遍历背包
            for (int i = m; i >= zero_num; --i) {
                for (int j = n; j >= one_num; --j) {
                    dp[i][j] = max(dp[i][j],dp[i-zero_num][j-one_num] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

