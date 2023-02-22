// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end



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
 * 整体思路：先移除多余空格，再整体反转，最后反转单词
 * 移除空格：如果暴力用erase移除时间复杂度很高，因为erase会将后边所有元素
 * 向前移动，覆盖删除。所以移除空格使用双指针法。
 * 反转：两个反转可以写一个函数，传入字符串和反转的起始和终止位置
 * 有一个重大发现，while 和 for的区别，for 的++操作是必须执行的，
 * while的++语句写在最后就可能被continue跳过。
 */
class Solution {
public:
    void reverse(string &s, int start, int end) {
        int left = start, right = end;
        while (left < right) {
            swap(s[left],s[right]);
            ++left;
            --right;
        }
    }

    void removeSpace(string &s) {
        int slow = 0, fast = 0;
        //移除前边空格
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ' ) {
            ++fast;
        }
            
        //移除中间多余空格
        for (; fast < s.size(); ++fast)
        {
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
            {
                continue;
            }
            else
            {
                s[slow++] = s[fast];
            }
        }
        //移除后边空格
        if (slow - 1 > 0 && s[slow-1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }

    }
    string reverseWords(string s) {
        removeSpace(s);
        reverse(s, 0, s.size() - 1);

        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

};
// @lc code=end

