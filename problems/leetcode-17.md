---
date:   2024-07-26
---

# Leetcode 17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

## Backtracking
Recursively construct the letter combinations. Record temporary output.

It requires to output all combinations. So it will be too costy in terms of memory to store some results.

## Use a queue
It can use a queue to store all results. And when adding a new digits, add all combinations letter to all temp string in the queue.

## Java Code
<pre>
<code>
class Solution {
    public void backtrack(String digits, int pos, String output, List<String> outputs) {
        if (pos >= digits.length()) {
            outputs.add(output);
            return;
        }
        int digit = digits.charAt(pos) - '0';
        switch (digit) {
            case 2:
                backtrack(digits, pos+1, output+"a", outputs);
                backtrack(digits, pos+1, output+"b", outputs);
                backtrack(digits, pos+1, output+"c", outputs);
                break;
            case 3:
                backtrack(digits, pos+1, output+"d", outputs);
                backtrack(digits, pos+1, output+"e", outputs);
                backtrack(digits, pos+1, output+"f", outputs);
                break;
            case 4:
                backtrack(digits, pos+1, output+"g", outputs);
                backtrack(digits, pos+1, output+"h", outputs);
                backtrack(digits, pos+1, output+"i", outputs);
                break;
            case 5:
                backtrack(digits, pos+1, output+"j", outputs);
                backtrack(digits, pos+1, output+"k", outputs);
                backtrack(digits, pos+1, output+"l", outputs);
                break;
            case 6:
                backtrack(digits, pos+1, output+"m", outputs);
                backtrack(digits, pos+1, output+"n", outputs);
                backtrack(digits, pos+1, output+"o", outputs);
                break;
            case 7:
                backtrack(digits, pos+1, output+"p", outputs);
                backtrack(digits, pos+1, output+"q", outputs);
                backtrack(digits, pos+1, output+"r", outputs);
                backtrack(digits, pos+1, output+"s", outputs);
                break;
            case 8:
                backtrack(digits, pos+1, output+"t", outputs);
                backtrack(digits, pos+1, output+"u", outputs);
                backtrack(digits, pos+1, output+"v", outputs);
                break;
            case 9:
                backtrack(digits, pos+1, output+"w", outputs);
                backtrack(digits, pos+1, output+"x", outputs);
                backtrack(digits, pos+1, output+"y", outputs);
                backtrack(digits, pos+1, output+"z", outputs);
                break;
        }
        return;
    }
    public List<String> letterCombinations(String digits) {
        List<String> outputs = new LinkedList<>();
        if (digits.length() == 0) {
            return outputs;
        }
        backtrack(digits, 0, "", outputs);
        return outputs;
    }
}
</code>
</pre>
