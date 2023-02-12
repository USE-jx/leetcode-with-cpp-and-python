/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) {
            int rest = s.size() - i ;
            if (rest >= k) {
                for (int left = i, right = i + k - 1; left < i + k / 2; ++left,--right)
                {
                    swap(s[left], s[right]);
                }
            } else {
                for (int left = i, right = i + rest - 1; left < i + rest / 2; ++left,--right)
                {
                    swap(s[left], s[right]);
                }
            }

        }
        return s;
    }
};
// @lc code=end

