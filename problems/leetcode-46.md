---
date:   2024-07-18
---

# Leetcode 46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

## Back tracking
Try each candidates, and recursively construct the answer.

## Java Code
<pre>
<code>
class Solution {
    public void backTracking(int[] nums, HashSet<Integer> used, List<Integer> output, List<List<Integer>> outputs) {
        if (nums.length == used.size()) {
            outputs.add(new ArrayList<Integer>(output));
            return;
        }
        for (int num : nums) {
            if (used.contains(num)) {
                continue;
            }
            output.add(num);
            used.add(num);
            backTracking(nums, used, output, outputs);
            used.remove(num);
            output.remove(output.size()-1);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        LinkedList<Integer> output = new LinkedList<>();
        LinkedList<List<Integer>> outputs = new LinkedList<>();
        backTracking(nums, new HashSet<Integer>(), output, outputs);
        return outputs;
    }
}
</code>
</pre>
