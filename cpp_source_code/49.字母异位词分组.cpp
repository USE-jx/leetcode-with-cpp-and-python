/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/**
 * 使用哈希表unordered_map,键是排好序的小串，值是字符串数组
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashTable;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hashTable[key].emplace_back(str);
        }
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// @lc code=end

