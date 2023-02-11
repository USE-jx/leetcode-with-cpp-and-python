/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 方法：双指针
 * 需要先将数组排序，这个很重要。
 * 只需要遍历一次数组，左指针指向下一个数，右指针指向末尾数。
 * 通过遍历和左右指针移动可以确定三元组，排序之后可以根据三数和
 * 大于或小于0确定怎么移动左右指针。
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return ans;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    --right;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    ++left;
                }
                else
                {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right; 
                    ++left;
                    --right;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

