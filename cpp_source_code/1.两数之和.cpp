// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 方法1：暴力解法，两次循环
 * 方法2：哈希表
 * 哈希表是用于判断一个是元素是否出现在表中
 * 首先循环遍历数组，对每个遍历的元素都去哈希表中是否存在
 * 目标值减去当前元素的值的元素，有就返回俩下标，
 * 哈希表用map，key存值，value存下标
 * 
 * 
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //方法1：暴力解法
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        //方法2：哈希表
        unordered_map<int, int> table;

        for (int i = 0; i < nums.size(); ++i) {
            auto iter = table.find(target - nums[i]);
            if (iter != table.end()) {
                return {iter->second, i};
            }
            table.insert(pair<int, int>(nums[i],i));
        }
        return {};

    }
};
// @lc code=end
