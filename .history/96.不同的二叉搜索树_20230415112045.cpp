/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i]
            }
        }
    }
};
// @lc code=end

