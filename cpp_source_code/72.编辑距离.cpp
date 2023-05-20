/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
/**
 * @brief 动态规划
 * dp[i][j]：i-1结尾的word1转换成j-1结尾的word2的最小操作数
 * 递推公式：
 * if (word1[i-1] = word2[j-1]) dp[i][j] = dp[i-1][j-1];
 * if (word[i-1] != word2[j-1])
 * word2删：dp[i][j] = dp[i][j-1] + 1
 * word1删: dp[i][j] = dp[i-1][j] + 1
 * word1换：dp[i][j] = dp[i-1][j-1] + 1 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 1; j <= word2.size(); ++j) dp[0][j] = j;

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

