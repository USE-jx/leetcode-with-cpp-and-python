/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

/**
 * 思路：
 * 方法一：
 * 遍历字符串，逐一放入栈中，若下一个元素和栈顶元素相同，同时删除两个
 * 最后把栈中元素赋给字符串
 * 方法二：
 * 直接用字符串作为栈
 * 
 */
class Solution {
public:
    string removeDuplicates(string s) {
        //方法二：
        string ans;

        for (const char c : s) {
            if (ans.empty() || ans.back() != c) {
                ans.push_back(c);
            } else {
                ans.pop_back();
            }
        }
        return ans;


        //方法一 写的太复杂了，忘了reverse咋用了
        // stack<char> char_stack;
        // string ans;

        // for (int i = 0; i < s.size(); ++i) {
        //     if (char_stack.empty()) {
        //         char_stack.push(s[i]);
        //     } else {
        //         if (char_stack.top() == s[i]) {
        //             char_stack.pop();
        //         } else {
        //             char_stack.push(s[i]);
        //         }
        //     }
        // }
        // int size = char_stack.size();
        // int size2 = size;
        // stack<char> temp;
        // while (size--) {
        //     char c = char_stack.top();
        //     temp.push(c);
        //     char_stack.pop();
        // }
        // while (size2--)
        // {
        //     char c = temp.top();
        //     temp.pop();
        //     ans.push_back(c);
        // }
        // return ans;

    }
};
// @lc code=end

