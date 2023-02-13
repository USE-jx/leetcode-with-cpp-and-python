/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
using namespace std;

/**
 * 方法1：暴力解法
 * 两次循环，时间复杂度o(n^2)，小循环中判断相等字符个数，记录
 * 大循环的起始位置，如果相等字符个数和needle长度相等说明是大
 * 字符串的一部分，返回起始位置，大循环结束就返回-1.
 * 方法2：KMP
 * 首先要构造needle前缀表存在next数组里，在遇到不匹配的字符时，
 * next数组会告知回退的位置，不用每次都回到第一个字符，haystack
 * 也不用每次都加1，减少了很多循环次数。
 * 
 */
class Solution {
public:
    void getNext(int *next, const string &s) {
        //j指向前缀末尾位置，i指向后缀末尾位置
        int j = 0; 
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i) {
            while (s[j] != s[i] && j > 0) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                ++j;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        //暴力解法
        // for (int i = 0; i < haystack.size(); ++i) {
        //     int start = i;
        //     if (haystack[start] == needle[0]) {
        //         for (int j = 0; j < needle.size(); ++j) {
        //             if (haystack[start] == needle[j]) ++start;
        //         }
        //         if (start-i == needle.size()) return i;               
        //     }
        // }
        // return -1;
        int size = needle.size();
        if (size == 0) {
            return  0;
        }
        int next[size];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
// @lc code=end

