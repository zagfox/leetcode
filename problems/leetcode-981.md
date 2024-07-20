---
date:   2024-07-19
---

# Leetcode 981. Time Based Key-Value Store

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

## HashMap to store LinkedList
Use a hash map where key is the input key. And value is a linked list of pair {timestamp, value}.

It works but timeout. The set and look up requires O(N) time.

## HashMap Java Code
<pre>
<code>
class TimeMap {
    class Entry {
        private int timestamp;
        private String value;
        public Entry(int timestamp, String value) {
            this.timestamp = timestamp;
            this.value = value;
        }
    }
    private HashMap<String, LinkedList<Entry>> keyEntries;

    public TimeMap() {
        keyEntries = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!keyEntries.containsKey(key)) {
            keyEntries.put(key, new LinkedList<Entry>());
        }
        LinkedList<Entry> entries = keyEntries.get(key);
        if (entries.isEmpty()) {
            entries.add(new Entry(timestamp, value));
            return;
        }
        // The position to insert the new entry to
        int pos = 0;
        for (;pos < entries.size(); ++pos) {
            Entry entry = entries.get(pos);
            if (entry.timestamp == timestamp) {
                // update entry and return
                entry.value = value;
                return;
            }
            if (entry.timestamp > timestamp) {
                break;
            }
        }
        entries.add(pos, new Entry(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        if (!keyEntries.containsKey(key)) {
            return "";
        }
        LinkedList<Entry> entries = keyEntries.get(key);
        int pos = 0;
        for (; pos < entries.size(); ++pos) {
            Entry entry = entries.get(pos);
            if (entry.timestamp == timestamp) {
                return entry.value;
            } else if (entry.timestamp > timestamp) {
                break;
            }
        }
        // pos is at the first entry that larger than required_ts, move it to prior element. Which is
        // the last entry that smaller than the required ts.
        --pos;
        // There is no stored ts < required_ts;
        if (pos == -1) {
            return "";
        }
        return entries.get(pos).value;
    }
}
</code>
</pre>

## HashMap to store TreeMap
Use a hash map where key is the input key. And value is another map, but that map's key is sorted.

## HashMap Java Code
<pre>
<code>
class TimeMap {
    private HashMap<String, TreeMap<Integer, String>> keyEntries;

    public TimeMap() {
        keyEntries = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!keyEntries.containsKey(key)) {
            keyEntries.put(key, new TreeMap<>());
        }
        keyEntries.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        if (!keyEntries.containsKey(key)) {
            return "";
        }
        TreeMap<Integer, String> entries = keyEntries.get(key);
        // Return the entry who's key is the greatest && <= given timestamp;
        Map.Entry<Integer, String> entry = entries.floorEntry(timestamp);
        if (entry == null) {
            return "";
        }
        return entry.getValue();
    }
}
</code>
</pre>