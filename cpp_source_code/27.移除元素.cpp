/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

/**
 * 如果开辟内存的话比较简单，只需要把不是val的值跳过，其他都存入新数组即可
 * 但是不能开辟新内存，这时候可以使用双指针,可以左边找值为val的位置，右边找
 * 值不为val的位置，当左等于右时，返回左位置，关键是循环条件左等于右。
 * 
 * 本题的双指针是开始两个指针一起右移，当指向值为val时，其中一个指针
 * 右移直到指向值不为val的位置，此时右指针的值赋给左指针，同时右移，
 * 两指针的差就是值为val的个数，所以右指针遍历完之后，左指针就指向数字末尾
 * 
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int size = nums.size();
        // int left = 0, right = 0;

        // while (right < size) {
        //     if (nums[right] != val) {
        //         nums[left++] = nums[right];
        //     }
        //     ++right;
        // }
        // return left;


        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            while (left <= right && nums[left] != val) {
                ++left;
            }
            while (left <= right && nums[right] == val) {
                --right;
            }
            if (left <= right) {
                nums[left++] = nums[right--];
            }
             
        } 
        return left;
    }
};
// @lc code=end

