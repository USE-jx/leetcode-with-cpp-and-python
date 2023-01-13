/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
/**
 * 这种需要记录元素出现次数并快速查找的就可以使用哈希表
 * 哈希表可以使用数组，set和map，本题因字母种类较少使用数组比较合适
 * 先遍历s，记录各字母出现的次数，再遍历t，把出现的字母次数减去
 * 如果最后记录的数组中各元素次数都是0，那么就是异位词
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashTable(26, 0);

        for (auto c : s) {
            ++hashTable[c-'a'];
        }
        for (auto c : t) {
            --hashTable[c-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (hashTable[i] != 0)
            return false;
        }
        return true;

    }
};
// @lc code=end

