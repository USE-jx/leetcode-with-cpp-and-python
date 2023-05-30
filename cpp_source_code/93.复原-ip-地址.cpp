/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    

    void backtracking(string s, int start_index, int point_num) {
        if (point_num == 3) {
            if (isValid(s, start_index, s.size()-1)) {
                result.push_back(s);
                return;
            }
        }

        for (int i = start_index; i < s.size(); ++i) {
            if (isValid(s, start_index, i)) {
                s.insert(s.begin() + i + 1, '.');
                ++point_num;
                backtracking(s, i + 2, point_num);
                --point_num;
                s.erase(s.begin() + i + 1);
            } else break;
        }
    }

    bool isValid(string s, int start, int end) {
        if ( start > end) return false;
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; ++i) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end

