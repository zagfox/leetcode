---
date:   2024-06-17
---

# Leetcode 232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported nativel

## Negative Negative is Positive
A single stack is LIFO. But if there are two stacks chaining togehter, the overall data structure is FIFO.


## Java Code
<pre>
<code>
class MyQueue {
    private Stack<Integer> s1, s2;

    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();        
    }
    
    public void push(int x) {
        s1.push(x);
    }
    
    public int pop() {
        if (!s2.empty()) {
            return s2.pop();
        }
        while (!s1.empty()) {
            s2.push(s1.pop());
        }
        return s2.pop();
    }
    
    public int peek() {
        if (!s2.empty()) {
            return s2.peek();
        }
        while (!s1.empty()) {
            s2.push(s1.pop());
        }
        return s2.peek();
    }
    
    public boolean empty() {
        return s1.empty() && s2.empty();
    }
}
</code>
</pre>