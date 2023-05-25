/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int start_index) {
        //终止条件
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        //横向遍历
        for (int i = start_index; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        } 
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k , 1);
        return result;
    }
};
// @lc code=end

