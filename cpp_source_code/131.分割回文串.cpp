/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;

    void backtracking(string s, int start_index) {
        if (start_index >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start_index; i < s.size(); ++i) {
            if (isHuiWen(start_index, i, s)) {
                string str = s.substr(start_index, i - start_index + 1);
                path.push_back(str);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isHuiWen(int start, int end, string s) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

