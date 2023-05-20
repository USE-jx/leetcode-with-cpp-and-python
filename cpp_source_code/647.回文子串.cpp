/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
/**
 * @brief 动态规划
 * dp[i][j]:[i,j]之间是否是回文串
 * 递推公式：
 * if (s[i] != s[j]) dp[i][j] = false;
 * if (s[i] == s[j]) {
 *  if (j-i <= 1) ans++; dp[i][j] = true;
 *  else if (dp[i+1][j-1]) ans++ dp[i][j] = true;
 * }
 * 遍历顺序：i从后向前，j从前向后
 * 
 */
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(), false));
        int ans = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i <= 1) {
                        ++ans;
                        dp[i][j] = true;
                    } else if (dp[i+1][j-1]) {
                        ++ans;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

