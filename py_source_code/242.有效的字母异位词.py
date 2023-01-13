#
# @lc app=leetcode.cn id=242 lang=python3
#
# [242] 有效的字母异位词
#

# @lc code=start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        table = [0] * 26

        for c in s:
            table[ord(c)-ord("a")] += 1
        for c in t:
            table[ord(c)-ord('a')] -= 1
        for i in range(26):
            if table[i] != 0:
                return False
        return True
# @lc code=end

