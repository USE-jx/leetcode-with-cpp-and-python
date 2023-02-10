/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
using namespace std;

/**
 * 方法：哈希数组
 * 哈希表是用来快速判断元素是否在表中，避免了一次循环，但是多分配了内存，
 * 相当于用空间换时间。
 * 本题因为字母种类较少，所以使用数组即可。字母的下标=字母-'a'。数组存储
 * 字母出现的个数。
 * 首先mag的长度要大于ran，否则肯定不能构成。
 * 把mag存起来，遍历看ran需要啥，如果出现mag中不够的字母，那对应数组值就变负数，
 * 此时直接返回false，如果一直没变负数，那就是true
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int array_table[26] = {0}; //must be initialed

        for (char c : magazine) {
            ++array_table[c - 'a'];
        }

        for (char c : ransomNote) {
            --array_table[c - 'a'];
            if (array_table[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

