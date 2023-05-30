/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief 树枝不用去重，都是一个集合的元素通过startindex可以
 * 不重复使用，树层需要去重，因为前一个相同元素形成的组合会包含
 * 后一个相同元素形成的组合。
 * 
 */
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &candidates, int target, int sum, int start_index, vector<bool> &used) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) {
                continue;
            }

            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i+1, used);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
        

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
        
    }
};
// @lc code=end

