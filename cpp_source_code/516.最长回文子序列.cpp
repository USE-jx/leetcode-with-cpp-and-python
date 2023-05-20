/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
/**
 * @brief 动态规划
 * dp[i][j]：[i,j]区间的最长回文子序列的长度
 * 递推公式：
 * if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
 * else {
 * dp[i][j] = max(dp[i][j-1],dp[i+1][j])
 * }
 * 
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;

        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
// @lc code=end

