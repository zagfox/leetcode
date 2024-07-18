---
date:   2024-07-18
---

# Leetcode 39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

## Back Tracking
For a given target sum, try each candidate separately, and recusively call the function to find # of combinations.

## Dynamic programing
Back tracking is not efficient. Because the same target number could have been calculated multiple times. Having a dp[i] array to denote the number of combinations for target number i.
Then dp[i] = Sum(dp[i-x] | for x in candidates)

But it didn't fit in here because the problem requires to output the combination list. To make it work, it needs to store the combination list for all target number, which may use too many memory.

## Java Code
<pre>
<code>
class Solution {
    public void dfs(int[] candidates, int target, List<Integer> output, List<List<Integer>> outputs) {
        if (target == 0) {
            outputs.add(new ArrayList<Integer>(output));
            return;
        }
        for (int candidate : candidates) {
            if (output.size() > 0 && candidate < output.get(output.size()-1)) {
                continue;
            }
            if (target - candidate < 0) {
                continue;
            }
            output.add(candidate);
            dfs(candidates, target - candidate, output, outputs);
            output.remove(output.size()-1);
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> output = new LinkedList<>();
        LinkedList<List<Integer>> outputs = new LinkedList<>();
        dfs(candidates, target, output, outputs);
        return outputs; 
    }
}
</code>
</pre>
