---
date:   2024-07-23
---

# Leetcode 78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

## Back Track

Use recursion to repeatedly append nums to temporary list. For each recursion
  1. Add output to the final container
  2. Choose one num from unselected nums, make sure it's bigger than previously selected one
  3. Add the num to temporary list, go to step 1

To avoid duplicate, each time the selected num should be larger than the previously selected one.

## Java Code
<pre>
<code>
class Solution {
    public void backTrack(HashSet<Integer> nums, LinkedList<Integer> output, List<List<Integer>> outputs) {
        outputs.add(new ArrayList<Integer>(output));
        if (nums.isEmpty()) {
            return;
        }

        for(int num : nums) {
            if (!output.isEmpty() && num <= output.getLast()) {
                continue;
            }
            HashSet<Integer> numsCopy = new HashSet<>(nums);
            numsCopy.remove(num);
            output.add(num);
            backTrack(numsCopy, output, outputs);
            output.removeLast();
        }
        return;

    }
    public List<List<Integer>> subsets(int[] nums) {
        HashSet<Integer> numsSet = new HashSet<>();
        for (int num : nums) {
            numsSet.add(num);
        }
        LinkedList<Integer> output = new LinkedList<>();
        List<List<Integer>> outputs = new LinkedList<>();
        backTrack(numsSet, output, outputs);
        return outputs;
    }
}
</code>
</pre>
