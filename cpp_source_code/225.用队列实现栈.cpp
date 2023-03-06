/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;

/**
 * 思路：
 * 1 两个队列：主要是pop，pop需要弹出最后一个元素，所以队列一可以弹出
 * n-1个元素，存到队列二，然后就能弹出最后一个元素了。弹出后再复制队列二
 * 的元素到队列一即可。
 * 
 * 2 一个队列：pop时只要将前n-1个元素直接加到队尾就行了
 * 
 * 注意：使用for循环时要注意循环条件会不会变
 */

class MyStack {
public:
    queue<int> queue_1;
    queue<int> queue_2;

    MyStack() {

    }
    //一个队列
    void push(int x)
    {
        queue_1.push(x);
    }

    int pop()
    {
        int size = queue_1.size();

        for (int i = 0; i < size - 1; ++i)
        {
            queue_1.push(queue_1.front());
            queue_1.pop();
        }
        int result = queue_1.front();
        queue_1.pop();
        return result;
    }

    int top()
    {
        int result = queue_1.back();
        return result;
    }

    bool empty()
    {
        if (queue_1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // //两个队列
    // void push(int x) {
    //     queue_1.push(x);
    // }
    
    // int pop() {
    //     int size = queue_1.size();
        
    //     for (int i = 0; i < size - 1; ++i)
    //     {
    //         queue_2.push(queue_1.front());
    //         queue_1.pop();
    //     }
    //     int result = queue_1.front();
    //     queue_1.pop();
    //     queue_1 = queue_2;
    //     while (!queue_2.empty()) {
    //         queue_2.pop();
    //     }
    //     return result;
    // }
    
    // int top() {
    //     int result = queue_1.back();
    //     return result;
    // }
    
    // bool empty() {
    //     if (queue_1.empty()) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
};


// @lc code=end

