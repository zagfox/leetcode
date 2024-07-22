---
date:   2024-07-21
---

# Leetcode 139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

## Back tracking
Recursively, check the target string subsequence [start, last], try all words in the directory, if there is a match for [start, pos], use that word, and recursively check the range of [pos, last].

The back tracking method is not efficient. It may hit the same range [start, last] multiple times. It can be optimized by memorizing whether range [start, last] has been examined and its result.

## Java Code
<pre>
<code>
class Solution {
    // check range [pos, end) for whether it can be composed by words in dictionary
    // visited is a map from pos -> state. State 0 is unvisited, 1 means visited and can compose, -1 means cannot compose.
    public boolean recursion(int pos, String s, HashSet<String> wordDict, HashMap<Integer, Integer> visited) {
        Integer state = visited.get(pos);
        if (state != null) {
            if (state == 1) return true;
            if (state == -1) return false;
        }
        if (pos == s.length()) {
            return true;
        }
        if (pos > s.length()) {
            return false;
        }
        // Word max length is 20
        for (int len = 1; len <= 20; ++len) {
            if (pos + len > s.length()) {
                continue;
            }
            String word = s.substring(pos, pos + len);
            if (!wordDict.contains(word)) {
                continue;
            }
            if (recursion(pos + len, s, wordDict, visited)) {
                visited.put(pos, 1);
                return true;
            }
        }
        visited.put(pos, -1);
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> dict = new HashSet(wordDict);
        HashMap<Integer, Integer> visited = new HashMap<>();
        return recursion(0, s, dict, visited);
    }
}
</code>
</pre>

## Dynamic programing
Use dp[i] to denote that the target string subrange [0, i] can be composed by words in the directory.

dp[i+1] = IfExist(dp[i+i-len] | for word in directory with size len)

<pre>
<code>
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        // dp[i] represent subrange [0, i) can be composed by dictionary.
        // Answer is dp[s.length()].
        int[] dp = new int[s.length()+1];
        dp[0] = 1;
        HashSet<String> dict = new HashSet<>(wordDict);
        for (int pos = 1; pos <= s.length(); ++pos) {
            // Word max length is 20.
            for (int len = 1; len <= 20; ++len) {
                int start = pos - len;
                if (start < 0) {    // word too long
                    continue;
                }
                if (dp[start] == 0) {    // range [0, start) was not able to be composed
                    continue;
                }
                String word = s.substring(start, start + len);
                if (wordDict.contains(word)) {
                    dp[pos] = 1;
                    break;
                }
            }
        }
        return dp[s.length()] == 1;
    }
}
</code>
</pre>