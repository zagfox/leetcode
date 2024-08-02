---
date:   2024-06-18
---

# Leetcode 155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

<h2>Two Stack</h2>
In addition to the normal stack, have another helper stack to only record numbers that could be potentially be the min element. That means, for each incoming number, only push to helper_stack if its value is smaller or equal to the helper_stack last recorded min value. When pop out an element, normal stack pop out, if value is the same as the helper_stack top, also pop.

<h2> Java Code </h2>
<pre>
<code>
class MinStack {
    Stack<Integer> stack = null;
    Stack<Integer> helper = null;

    public MinStack() {
        stack = new Stack<Integer>();
        helper = new Stack<Integer>();    
    }
    
    public void push(int val) {
        stack.push(val);
        if (helper.empty() || val <= helper.peek()) {
            helper.push(val);
        }
    }
    
    public void pop() {
        int val = stack.pop();
        if (val == helper.peek()) {
            helper.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return helper.peek();
    }
}
</code>
</pre>

