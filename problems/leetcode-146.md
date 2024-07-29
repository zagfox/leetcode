---
date:   2024-07-28
---

# Leetcode 146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

## PriorityQueue
PriorityQueue can sort the item by last used time. But its insert is log(N).

## LinkedList to store key access
Use a linkedList to store key access. Recent accessed is placed at front. There can be multiple item of the same key in the linked list. Another hashMap is introduced to store each key's count in the linked list.

When the LRU exceed its capacity, the end of the linkedList element is removed. If there are still multiple list node of this key, don't delete it. Instead, continue removing the end of the linked list. Until that element only has one occurance. 

## Java Code
<pre>
<code>
class LRUCache {
    private HashMap<Integer, Integer> values;
    // All put/add access to key is recorded, recent access is placed at head.
    // keyCount is the count of a key in the keyAccess list.
    private LinkedList<Integer> keyAccess;
    private HashMap<Integer, Integer> keyCount;
    private int capacity;

    public LRUCache(int capacity) {
        values = new HashMap<>();
        keyAccess = new LinkedList<>();
        keyCount = new HashMap<>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!values.containsKey(key)) {
            return -1;
        }
        keyAccess.addFirst(key);
        keyCount.put(key, keyCount.get(key)+1);
        return values.get(key);
    }
    
    public void put(int key, int value) {
        values.put(key, value);
        keyAccess.addFirst(key);
        keyCount.put(key, keyCount.getOrDefault(key, 0) + 1);

        while (values.size() > capacity) {
            int candidate = keyAccess.removeLast();
            keyCount.put(candidate, keyCount.get(candidate)-1);
            if (keyCount.get(candidate) == 0) {
                values.remove(candidate);
            }
        }
    }
}
</code>
</pre>
