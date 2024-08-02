---
date:   2024-06-18
---

# Leetcode 150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

## Stack
A feature of reverse polish notation is that, when it encounter an operator, the operand is already calculated. And as there is no variable like X or Y, all the operands are already available. As operators are offered first and used later, a stack can be used to store operands.

## Java Code
<pre>
<code>
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            try {
                int val = Integer.parseInt(token);
                stack.push(val);
            } catch (NumberFormatException e) {
                int op2 = stack.pop();
                int op1 = stack.pop();
                switch (token) {
                case "+":
                    stack.push(op1+op2);
                    break;
                case "-":
                    stack.push(op1-op2);
                    break;
                case "*":
                    stack.push(op1*op2);
                    break;
                case "/":
                    stack.push(op1/op2);
                    break;
                }
            }
        }
        return stack.pop();
    }
}
</code>
</pre>

