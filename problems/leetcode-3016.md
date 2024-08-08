---
date:   2024-08-07
---

# Leetcode 3016. Minimum Number of Pushes to Type Word II

You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

## Re-arrange based on char frequency
Calculate word's char frequency. For high frequency ones, assign it to min length number.

## Java Code
<pre>
<code>
class Solution {
    public int minimumPushes(String word) {
        TreeMap<Character, Integer> charFreq = new TreeMap<>();
        for (char ch : word.toCharArray()) {
            charFreq.put(ch, charFreq.getOrDefault(ch, 0) + 1);
        }
        // Each number's char list.
        TreeMap<Integer, List<Character>> numCharList= new TreeMap<>();
        for (int i = 2; i <= 9; ++i) {
            numCharList.put(i, new LinkedList<Character>());
        }
        HashMap<Character, Integer> charPress = new HashMap<>();

        while (!charFreq.isEmpty()) {
            // pick top freq Char
            char pickChar = '@';
            int maxFreq = 0;
            for (char ch : charFreq.keySet()) {
                int freq = charFreq.get(ch);
                if (freq > maxFreq) {
                    pickChar = ch;
                    maxFreq = freq;
                }
            }

            // Pick the num with minimum cnt
            int pickNum = 2;
            int cnt = numCharList.get(2).size();
            for (int i = 2; i <= 9; ++i) {
                if (numCharList.get(i).size() < cnt) {
                    pickNum = i;
                    cnt = numCharList.get(i).size();
                }
            }
            //System.out.println("char " + pickChar + " freq is " + charFreq.get(pickChar) + " map to num " + pickNum + " with press " + (cnt+1));
            numCharList.get(pickNum).add(pickChar);
            charPress.put(pickChar, cnt+1);

            charFreq.remove(pickChar);
        }

        int output = 0;
        for (char ch : word.toCharArray()) {
            output += charPress.get(ch);
            //System.out.println("char is " + ch + " add press " + charPress.get(ch) + " total is " + output);
        }
        return output;
    }
}
</code>
</pre>


## Math with greedy
Get the frequencies, for high frequency, rank 0-7, assign cnt 1. for frequency 8-15, assign cnt 2, etc

## Java Code
<pre>
<code>
class Solution {
    public int minimumPushes(String word) {
        Integer[] frequency = new Integer[26];
        for (int i = 0; i < 26; ++i) {
            frequency[i] = 0;
        }
        for (char ch : word.toCharArray()) {
            ++frequency[ch-'a'];
        }
        Arrays.sort(frequency, Collections.reverseOrder());
        
        int output = 0;
        for (int rank = 0; rank < 26; ++rank) {
            if (frequency[rank] == 0) {
                continue;
            }
            int cnt = frequency[rank];
            output += (rank + 8) / 8 * cnt;
        }
        return output;
    }
}
</code>
</pre>