/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
/**
 * 本题没说交集要连在一起，有共同元素就行
 * 方法1：数组存储一个数组元素出现的次数，set存储结果去重
 * 本题数组长度较小，使用数组效率会更高一些
 * 方法2：都用set存储
 * 练一练set，如果数组长度大或者某个数字比较大还是得用set
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // //方法1：
        // unordered_set<int> result;
        // int numsArray[1001] = {0};
        // int size1 = nums1.size(), size2 = nums2.size();
        // for (int i = 0; i < size1; ++i) {
        //     numsArray[nums1[i]] = 1; 
        // }
        // for (int i = 0; i < size2; ++i) {
        //     if (numsArray[nums2[i]] == 1) {
        //         result.insert(nums2[i]);
        //     } 
        // }
        // return vector<int> (result.begin(), result.end());
        //方法2：
        unordered_set<int> result;
        unordered_set<int> numsSet (nums1.begin(), nums1.end());

        for (int nums : nums2) {
            if (numsSet.find(nums) != numsSet.end()) {
                result.insert(nums);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};
// @lc code=end

