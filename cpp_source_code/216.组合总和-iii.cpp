/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int start_index) {
        if(path.size() == k) {
            int sum = 0;
            for (int i = 0; i < k; ++i) {
                sum += path[i];
            }
            
            if (sum == n) {
                result.push_back(path);
            }
            return;
        }

        for (int i = start_index; i <= 9 - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};
// @lc code=end

