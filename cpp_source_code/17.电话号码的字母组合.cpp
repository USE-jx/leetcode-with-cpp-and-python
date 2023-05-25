/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    const string letter_map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;
    string path;

    void backtracking(string digits, int index) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        int digits_i = digits[index] - '0';
        string letters = letter_map[digits_i];
        for (int i = 0; i < letters.size(); ++i) {
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
        backtracking(digits, 0);
        return result;
    }
};
// @lc code=end

