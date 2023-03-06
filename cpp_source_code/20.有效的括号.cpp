/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string> 
#include <stack>
using namespace std;

/**
 * 思路：
 * 首先，奇数个字符一定不匹配
 * 定义一个栈，遍历字符串，
 * 如果遍历到三种左括号就把三种对应的右括号入栈，
 * 如果遍历到三种右括号，判断是否与栈顶右括号相同，若不相同则不匹配，若相同弹出栈顶
 * 如果遍历过程中栈空了，说明右括号多了，不匹配
 * 最后如果遍历完字符串，栈还没空，说明左括号多了，不匹配
 * 
 * 注意：使用一堆else if 要保证各条件之间独立
 */
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if (size % 2 != 0) return false;
        stack<char> char_stack;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '(') char_stack.push(')');
            else if (s[i] == '[') char_stack.push(']');
            else if (s[i] == '{') char_stack.push('}');
            else if (char_stack.empty() || char_stack.top() != s[i]) return false;
            else char_stack.pop();
        }
        if (char_stack.empty()) {
            return true;
        } else {
            return false;
        }

    }
};
// @lc code=end

