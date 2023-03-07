/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>
using namespace std;

/**
 * 思路：
 * 遍历字符数组，逐一入栈，遇到一个运算符就取出栈顶的两个元素运算
 * 
 * 破题没啥意思
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       

        stack<long long> int_stack;
        int ans = 0;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || 
                tokens[i] == "*" || tokens[i] == "/") {
                long long num2 = int_stack.top();
                int_stack.pop();
                long long num1 = int_stack.top();
                int_stack.pop();
                if (tokens[i] == "+") int_stack.push(num1 + num2);
                if (tokens[i] == "-") int_stack.push(num1 - num2);
                if (tokens[i] == "*") int_stack.push(num1 * num2);
                if (tokens[i] == "/") int_stack.push(num1 / num2);
            } else {
                int_stack.push(stoll(tokens[i]));
            }
        }
        ans = int_stack.top();
        return ans;

    }
};
// @lc code=end

