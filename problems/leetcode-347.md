---
date:   2024-08-07
---

# Leetcode 347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

## Sorting
Sort and then find out top unique numbers.

# Priority heap
Count number's frequency, put it in a minHeap, only keep k numbers in the heap.

Complexity: O(N * log(k))

## Java Code
<pre>
<code>
class Solution {
    class Entry {
        int num;
        int freq;
        public Entry(int num, int freq) {
            this.num = num;
            this.freq = freq;
        }
    }
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Entry> heap = new PriorityQueue<>(new Comparator<>() {
            public int compare(Entry a, Entry b) {
                return Integer.compare(a.freq, b.freq);
            }
        });
        HashMap<Integer, Integer> frequency = new HashMap<>();
        for (int num : nums) {
            frequency.put(num, frequency.getOrDefault(num, 0) + 1);
        }
        for (int num : frequency.keySet()) {
            int freq = frequency.get(num);
            heap.add(new Entry(num, freq));
            if (heap.size() > k) {
                heap.poll();
            }
        }
        int[] output = new int[k];
        int i = 0;
        for (Iterator<Entry> iter = heap.iterator(); iter.hasNext();) {
            Entry entry = iter.next();
            output[i++] = entry.num;
        }
        return output;
    }
}
</code>
</pre>
