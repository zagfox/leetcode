---
date:   2024-07-30
---

# Leetcode 49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Sort each word
Like brute force, sort each word based on letter sequence. But the output requires to be the original word. So, we'd keep the original input unchanged, and each str has an index. 
Use a map from "ordered string" -> indexes to group the words.

## Java Code
<pre>
<code>
class Solution {
    public String convert(String str) {
        char[] array = str.toCharArray();
        Arrays.sort(array);
        return new String(array);
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<Integer>> leaderIndexes = new HashMap<>();
        for (int i = 0; i < strs.length; ++i) {
            String leader = convert(strs[i]);
            if (!leaderIndexes.containsKey(leader)) {
                leaderIndexes.put(leader, new LinkedList<Integer>());
            }
            leaderIndexes.get(leader).add(i);
        }
        List<List<String>> outputs = new LinkedList<>();
        leaderIndexes.forEach((leader, indexes) -> {
            List<String> output = new LinkedList<>();
            for (int index : indexes) {
                output.add(strs[index]);
            }
            outputs.add(output);
        });
        return outputs;
    }
}
</code>
</pre>
