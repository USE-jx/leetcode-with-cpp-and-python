/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 方法：双指针
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            if (target >= 0 && nums[i] > target) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                    break; 
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = size - 1;
                
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        --right;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        ++left;
                    }
                    else
                    {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

