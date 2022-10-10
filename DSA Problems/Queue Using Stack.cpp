/*Problem Link: https://leetcode.com/problems/implement-queue-using-stacks/description/



Problem Description:
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.



Approach: The idea is to make use of 2 stacks and work as follows:
          1. In case of PUSH , simply push the element to first stack
          2. In case of POP, element will be popped from second stac always, therefore if the stack 2 is not empty pop the element from it else pop all elements from
             stack 1 and push it to stack 2 and the pop the element from stack 2.
          3. In case of PEEK, perform the operations exactly as in peek just do not pop from stack2  instead return the top element
          4. In case of EMPTY CHECK make sure both the stacks are empty for the Oueue to be empty

Using this algorithm we can implement all the functionalities of Queue using stacks.

There would only be certain instances where the time complexity would go O(n) for ceratin operations. Most of the operations would be O(1). Thus we say it is amortised time complexity



Time Complexity:  O(1) (amortized --  performing n operations will take overall O(n) time even if one of those operations may take longer)
Space Complexity: O(2n)




Implementation in C++:

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue
{
public:
    stack<int> st1, st2;

    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {

        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ele = st2.top();
        st2.pop();
        return ele;
    }

    int peek()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};
