---
date:   2024-07-28
---

# Leetcode 621. Task Scheduler

You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

## Greedy
Each time, execute the runnable one, with most pending tasks.

## Java Code
<pre>
<code>
class Solution {
    public boolean finished(int[] remaining) {
        for (int remain : remaining) {
            if (remain > 0) {
                return false;
            }
        }
        return true;
    }
    // Select a task to run. If none can be selected return '#'.
    public char select(int[] remaining, int[] waiting) {
        // Select the runnable task with max remaining.
        int maxRemain = -1;
        char task = '#';
        for (int i = 0; i < 26; ++i) {
            if (waiting[i] > 0) {
                continue;
            }
            if (remaining[i] > maxRemain) {
                maxRemain = remaining[i];
                task = (char)('A' + i);
            }
        }
        return task;
    }
    public int leastInterval(char[] tasks, int n) {
        // How many tasks are remaining for A, B, etc.
        int[] remaining = new int[26];
        // waiting time of tasks A, B, etc. 
        int[] waiting = new int[26];
        for (char ch : tasks) {
            ++remaining[ch-'A'];
        }
        int cycle = 0;
        while (!finished(remaining)) {
            char task = select(remaining, waiting);
            if (task != '#') {
                --remaining[task-'A'];
                waiting[task-'A'] = n+1;
            }
            // End this cycle
            for (int i = 0; i < 26; ++i) {
                if (waiting[i] > 0) {
                    --waiting[i];
                }
            }
            ++cycle;
        }
        return cycle;
    }
}
</code>
</pre>

## Math solution
Without simulation, TBD
https://www.cnblogs.com/grandyang/p/7098764.html