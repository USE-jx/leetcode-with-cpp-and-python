/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector> 
#include <deque>
using namespace std;

/**
 * 方法一：暴力解法
 * 每次移动窗口记录下来，存到数组，遍历求最大值，这样如果窗口
 * 很大，循环遍历复杂度很大。
 * 
 * 方法二：自定义队列
 * 需要push，pop和getMaxValue三个操作
 * 遍历数组，每一次都要队列都要pop和push，队列大小不一定是k，
 * 每次push都把小于push的值的元素弹出去，所以导致每次pop的值
 * 有可能不是nums[i]，这时就不需要pop了，getMaxValue就是取
 * 队列的头一个元素。
 * 
 */
class Solution {
public:

    class MyQueue {
    public:
        deque<int> int_queue;

        void pop(int value) {
            if (!int_queue.empty() && value == int_queue.front()) {
                int_queue.pop_front();
            }
        }

        void push(int value) {
            while (!int_queue.empty() && value > int_queue.back()) {
                int_queue.pop_back();
            }
            int_queue.push_back(value);
        }

        int getMaxValue() {
            return int_queue.front();
        }

    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue my_queue;
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            my_queue.push(nums[i]);
        }
        ans.push_back(my_queue.getMaxValue());
        for (int i = k; i < nums.size(); ++i) {
            my_queue.pop(nums[i - k]);
            my_queue.push(nums[i ]);
            ans.push_back(my_queue.getMaxValue());
        }
        return ans;


    }
    //方法一：暴力解法 会超时
    // //求数组最大值
    // int getMaxValue(vector<int> nums) {
    //     int max = -10000;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         max = max > nums[i] ? max : nums[i];
    //     }
    //     return max;
    // }

    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int ans_size = nums.size() - k + 1;
    //     vector<int> ans;
        
    //     for (int i = 0; i < ans_size; ++i) {
    //         vector<int> temp;
    //         for (int j = 0; j < k; ++j) {
    //             temp.push_back(nums[j+i]);
    //         }
    //         int max = getMaxValue(temp);
    //         ans.push_back(max);
    //     }
    //     return ans;

    // }
};
// @lc code=end

