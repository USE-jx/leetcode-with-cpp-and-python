/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
/**
 * 先用哈希表把p包含的字母和个数存储起来，然后遍历s
 * 因为只有26个字母，所以用数组即可
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> sCount(26,0);
        vector<int> pCount(26,0);
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) return vector<int>();

        for (auto c : p) {
            ++pCount[c-'a'];
        }

        int left = 0;
        for (int right = 0; right < sLen; ++right) {
            if (right < pLen) {
                ++sCount[s[right]-'a'];
                if (sCount == pCount)
                    ans.emplace_back(0);
            } else{
                
                --sCount[s[left] - 'a'];
                ++sCount[s[right] - 'a'];
                ++left;
                if (sCount == pCount)
                {
                    ans.emplace_back(left);
                }
            }
            
        }
        return ans;

    }
};
// @lc code=end

