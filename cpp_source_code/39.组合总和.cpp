/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> candidates, int target, int sum, int start_index) {
        if ( sum > target) return; 

        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

