/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 方法：哈希表map
 * 两数之和是遍历一个数组，去哈希表中找是否存在目标值减去当前值的元素。
 * 四数相加可以借鉴目标值减去当前值的想法，不同之处是四个数组，四个数组怎么处理？
 * 如果是目标值减去当前值就需要把四个数组分成两组，13或22，由于13分组遍历就需要循环三次，复杂度0（n^3）了，
 * 而22分组只需要O(n^2),所以22分组，把前两个数组的所有可能元素和存入map的key，value则是元素和出现次数
 * 最后再遍历后两个数组，查哈希表并统计次数
 * 
 */
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> map_table;

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                int sum = nums1[i] + nums2[j];
                ++map_table[sum];
            }
        }

        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                int sum = nums3[i] + nums4[j];
                if (map_table.find(0-sum) != map_table.end()) {
                    ans += map_table[0-sum];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

