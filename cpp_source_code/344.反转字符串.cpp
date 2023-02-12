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
 * 方法：双指针法
 * 左右两个指针向中间缩，调用swap函数交换一下
 * 
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i = 0, j = size - 1; i < size / 2; ++i, --j) {
            swap(s[i],s[j]); //swap就是开辟个中间变量那种交换
        }
    }
};
// @lc code=end

