/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 看题想法：不分配额外数组空间首先就得想到双指针，然后数组整体反转可以前后
 * 各一个指针，两个指针所指的值边向中间移动边互换，两指针重合结束循环
 * 
 * 想法对了，直接通过了。
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int left = 0, right = size - 1;

        while (left < right) {
            swap(s[left], s[right]);

            ++left;
            --right;
        }
    }
};
// @lc code=end

