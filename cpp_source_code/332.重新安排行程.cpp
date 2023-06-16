// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem332.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<string, map<string, int>> targets;
    vector<string> result;

    bool backtracking(vector<vector<string>>& tickets) {
        if (result.size() == tickets.size() + 1) {
            return true;
        }

        for (pair<const string, int> &target : targets[result[result.size()-1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(tickets)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const vector<string> &vec : tickets) {
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets);
        return result;
    }
};
// @lc code=end

