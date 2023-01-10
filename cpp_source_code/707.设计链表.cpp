/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
/**
 * 方法1：单链表
 * 首先自定义一个简单的链表节点类，有val和next两个属性，一个能赋值的构造函数
 * 链表构造函数定义一个虚拟头节点，长度为0
 * 1 获取索引的链表节点值，index范围是[0,size-1],不在范围内返回-1，
 * 如果在范围内，构造当前节点指针遍历链表，找到index的节点，返回节点值
 * 2 头节点之前插入值为val的新节点，new一个节点newNode，让新节点指向头节点，
 * 虚拟头节点指向新节点，大小加一
 * 3 将值为val的节点加到链表最后一个元素，new一个新节点newNode，遍历找到尾节点，
 * 尾节点指向null作为条件，让尾节点指向新节点即可，新节点默认指向null
 * 4 在索引节点前添加值为val的节点，要求：
 * 如果index为链表长度，则该节点添加到表尾，index-1就是尾
 * 如果index大于链表长度，不插入节点
 * 如果index小于0，在头部插入节点
 * 然后就是找到index节点，插入操作，上面都有类似操作
 * 5 删除链表中第index个节点，找到index，删除操作，释放内存
 * 注意：添加或删除节点需要找到index前一个节点
 * 方法2：双链表
 * 首先构造一个简单的双链表节点类，有val和prev和next三个属性，一个赋值的构造函数
 * 双链表定义头和尾两个哨兵节点，链表长度
 * 1 找索引节点需要多考虑是从头找近还是从尾找近
 * 23头插和尾插可以通过4index之前插实现，所以完成4就完成2和3了
 * 
 */
class MyLinkedList {
public:
//方法1
//     //定义链表节点类
//     struct ListNode
//     {
//         int val;
//         ListNode *next;
//         ListNode(int x) : val(x), next(nullptr) {}
//     };
    
//     MyLinkedList() {
//         _dummyHead = new ListNode(0);
//         _size = 0;
//     }
    
//     int get(int index) {
//         //索引无效返回-1
//         if (index < 0 || index > (_size - 1)) {
//             return -1;
//         }
//         //遍历，构造当前节点指针
//         ListNode *currentNode = _dummyHead->next;
//         while (index--) {
//             currentNode = currentNode->next;
//         }
//         return currentNode->val;
//     }
    
//     void addAtHead(int val) {
//         ListNode *newNode = new ListNode(val);
//         newNode->next = _dummyHead->next;
//         _dummyHead->next = newNode;
//         _size++;
//     }
    
//     void addAtTail(int val) {
//         ListNode *newNode = new ListNode(val);
//         ListNode *currentNode = _dummyHead;
//         while (currentNode->next != nullptr) {
//             currentNode = currentNode->next;
//         }
//         currentNode->next = newNode;
//         _size++;
//     }
    
//     void addAtIndex(int index, int val) {
//         if (index > _size) return;
//         if (index < 0) index = 0; //小于0就插在头节点前
//         ListNode *newNode = new ListNode(val);
//         ListNode *currentNode = _dummyHead; //遍历得到index节点的前一个节点
//         while (index--) {
//             currentNode = currentNode->next;
//         }
//         newNode->next =currentNode->next;
//         currentNode->next = newNode;
//         _size++;
//     }
    
//     void deleteAtIndex(int index) {
//         if (index < 0 || index > (_size - 1)) return;
//         ListNode *currentNode = _dummyHead; //找到删除节点的前一个节点
//         while (index--) {
//             currentNode = currentNode->next;
//         }
//         ListNode *toBeDelete = currentNode->next;
//         currentNode->next = currentNode->next->next;
//         delete toBeDelete;
//         _size--;
//     }
// private:
//     ListNode *_dummyHead;
//     int _size;
//方法2
public:
    // 定义双链表节点
    struct DListNode
    {
        int val;
        DListNode *prev, *next;
        DListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    };

    MyLinkedList() {
        _size = 0;
        _head = new DListNode(0);
        _tail = new DListNode(0);
        _head->next = _tail;
        _tail->prev = _head;
    }

    int get(int index) {
        //如果不在范围内[0,size-1]，返回-1
        if (index < 0 || index >= _size) return -1;
        //在范围内，判断离头和尾哪个近
        DListNode *currentNode;
        if (index + 1 < _size - index) {
            currentNode = _head;
            //单链表是用while(--)也可以用for循环
            for (int i = 0; i <= index; ++i) {//因为从头哨兵节点开始，多加一次
                currentNode = currentNode->next;
            }
        } else {
            currentNode = _tail;
            for (int i = 0; i < _size - index; ++i) {
                currentNode = currentNode->prev;
            }
        }
        return currentNode->val;
    }

    void addAtHead(int val) {
        addAtIndex(0,val);
    }

    void addAtTail(int val) {
        addAtIndex(_size,val);
    }

    void addAtIndex(int index, int val) {
        //如果大于size，不插入
        if (index > _size) return;
        //如果小于0，就等于零
        if (index < 0) index = 0;
        //new一个新节点
        DListNode *newNode = new DListNode(val);
        //因为需要在index前插入，所以需要找到index-1和index两个结点指针
        DListNode *pred, *succ; //prev就是找到index-1，succ就是index
        if (index < _size - index) { //判断从前遍历还是从后遍历
            pred = _head;
            for (int i = 0; i < index; ++i) {
                pred = pred->next;
            }
            succ = pred->next;
        } else {
            succ = _tail;
            for (int i = 0; i < _size - index; ++i) {
                succ = succ->prev;
            }
            pred = succ->prev;
        }
        //index-1和index找到了，先把新节点的prev和next安排好，再断开pred和succ
        newNode->next = succ;
        newNode->prev = pred;
        pred->next = newNode;
        succ->prev = newNode;
        ++_size;
    }

    void deleteAtIndex(int index) {
        //pred和succ代表index的前后节点
        if (index < 0 || index >= _size) return;
        DListNode *pred, *succ;
        if (index < _size - index) {
            pred = _head;
            for (int i = 0; i < index; ++i) {
                pred = pred->next;
            }
            succ = pred->next->next;
        } else {
            succ = _tail;
            for (int i = 0; i < _size - index - 1; ++i) {
                succ = succ->prev;
            }
            pred = succ->prev->prev;
        }
        DListNode *toBeDelete = pred->next;
        pred->next = succ;
        succ->prev = pred;
        delete toBeDelete;
        --_size;
    }

private:
    DListNode *_head, *_tail;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

