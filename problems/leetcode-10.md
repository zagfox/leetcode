---
date:   2024-08-10
---

# Leetcode 10. Regular Expression Matching

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

## Two pointer
One pointer p1 pointing at pattern, and record pattern's state. 3 types
  1. raw chars
  2. . which can match anything
  3. something + * (which can match multiple times of previous pattern)
The hard problem is how to handle *, because first of all, it can match 0 or multiple times. Seems that it needs to use enumeration, to check if there is one way to match.

For implementation, refer
https://www.cnblogs.com/grandyang/p/4461713.html

## Java Code
<pre>
<code>

</code>
</pre>
