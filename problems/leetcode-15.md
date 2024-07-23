---
date:   2024-07-23
---

# Leetcode 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

## HashMap
First sort the input array. Then use hash map to store the last seen position of a number.
Iterate the sorted arrary with two pointer, and use hashmap to find the 3rd number position.

## Java Code
<pre>
<code>
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        HashMap<Integer, Integer> lastSeen = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            lastSeen.put(nums[i], i);
        }
        List<List<Integer>> outputs = new LinkedList<>();
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                int target = 0 - nums[i] - nums[j];
                Integer pos = lastSeen.get(target);
                if (pos != null && pos > j) {
                    LinkedList<Integer> output = new LinkedList<>();
                    output.add(nums[i]);
                    output.add(nums[j]);
                    output.add(nums[pos]);
                    outputs.add(output);
                }
                // No duplicate, each j must be different
                while (j+1 < nums.length && nums[j] == nums[j+1]) {
                    ++j;
                }
            }
            // No duplicate, each i must be different
            while (i+1 < nums.length && nums[i] == nums[i+1]) {
                ++i;
            }
        }
        return outputs;
    }
}
</code>
</pre>

## left right goes middle
This approach didn't use hashmap to store the last seen position. Select first number first, then on its right, use left/right pointer goes to middle approach.

## Java Code
<pre>
<code>
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> outputs = new LinkedList<>();
        for (int i = 0; i < nums.length;) {
            int target = -nums[i];
            int j = i+1, k = nums.length - 1;
            while (j < k) {
                int diff = nums[j] + nums[k] - target;
                if (diff == 0) {
                    List<Integer> output = new ArrayList<>();
                    output.add(nums[i]);
                    output.add(nums[j]);
                    output.add(nums[k]);
                    outputs.add(output);
                    ++j;
                    --k;
                    // no diff, each j and k must be different
                    while(j < nums.length && nums[j-1] == nums[j]) ++j;
                    while(k >= 0 && nums[k] == nums[k+1]) --k;
                } else if (diff > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
            ++i;
            // no diff, each i must be different
            while(i < nums.length && nums[i-1] == nums[i]) ++i;
        }
        return outputs;
    }
}
</code>
</pre>