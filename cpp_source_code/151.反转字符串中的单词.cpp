/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;

/**
 * 方法：双指针
 * 1 整体反转
 * 2 快慢指针去空格
 * 3 单词内部反转
 * 这题太强了
 */
class Solution {
public:
    void reverseStr(string &s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i],s[j]);
        }
    }

    void deleteExtraSpace(string &s) {
        int fast = 0, slow = 0;
        while (fast < s.size()) {
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (s[fast] != ' ' && fast < s.size()) {
                    s[slow++] = s[fast++];
                } 
            }
            ++fast;
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        deleteExtraSpace(s);
        reverseStr(s, 0, s.size()-1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                reverseStr(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    
    }
};
// @lc code=end

