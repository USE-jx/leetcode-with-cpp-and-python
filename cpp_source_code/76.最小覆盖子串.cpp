/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
/**
 * 滑动窗口法和哈希表
 * 用两个哈希表，先用一个t_map记录t中的元素和个数，右指针遍历数组，
 * 当s中出现t中元素，存入s_map，如果s_map元素个数都大于等于t_map中元素个数时，左指针右移
 * s_map中左指针指向元素的数量减一，
 *
 */

class Solution
{
public:
    unordered_map<char, int> s_map, t_map;

    bool check()
    {
        for (const auto &c : t_map)
        {
            if (s_map[c.first] < c.second)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int size = s.size();
        int left = 0, right = 0, minLength = INT_MAX;
        string ans;
        int ansL = -1;

        // t中元素及数量记录
        for (const auto &c : t)
        {
            ++t_map[c];
        }

        for (; right < size; ++right)
        {
            if (t_map.find(s[right]) != t_map.end())
            {
                ++s_map[s[right]];
            }

            while (check() && left <= right)
            {
                if (minLength > right - left + 1)
                {
                    minLength = right - left + 1;
                    ansL = left;
                }
                if (t_map.find(s[left]) != t_map.end())
                {
                    --s_map[s[left]];
                }
                ++left;
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, minLength);
    }
};
// @lc code=end
