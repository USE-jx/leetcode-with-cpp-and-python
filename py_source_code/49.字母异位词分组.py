#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#

# @lc code=start
from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)

        for str in strs:
            key = ''.join(sorted(str))
            mp[key].append(str)
        return list(mp.values())
            
# @lc code=end

