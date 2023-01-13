# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        sLen, pLen = len(s), len(p)
        ans = []
        sCount = [0] * 26
        pCount = [0] * 26
        if sLen < pLen:
            return ans
        for c in p:
            pCount[ord(c)-ord('a')]+=1
            
        left = 0
        for right in range(sLen):
            if right < pLen:
                sCount[ord(s[right])-ord('a')]+=1
                
                if sCount == pCount:
                    ans.append(0)
            else:
                sCount[ord(s[left])-ord('a')]-=1
                sCount[ord(s[right])-ord('a')]+=1
                left+=1
                if sCount == pCount:
                    ans.append(left)
        return ans
        
# @lc code=end

