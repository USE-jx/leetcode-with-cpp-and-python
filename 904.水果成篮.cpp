/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
/**
 * 滑动窗口法，用哈希表unordered_map存储窗口内的数以及出现的次数
 * 右指针右移过程中记录种类及个数，更新返回值树的棵树右减左加一
 * 当种类超过两种时，左指针对应的值减一，减到0就删除key，左指针右移，
 *
 */
// @lc code=start
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int size = fruits.size();
        int left = 0, right = 0, ans = 0;
        unordered_map<int, int> class_count;

        for (; right < size; ++right)
        {
            ++class_count[fruits[right]];
            while (class_count.size() > 2)
            {
                auto it = class_count.find(fruits[left]);
                (it->second)--;
                if (it->second == 0)
                {
                    class_count.erase(it);
                }
                ++left;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
