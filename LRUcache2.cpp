#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// class to define cache entry
class Entry {
public:
	int key;
	int value;
	Entry(int _key, int _value) {
		key = _key;
		value = _value;
	}
};

// Use hash map, O(1) to get and set
class LRUCache{
private:
	int max_size;
	list<Entry> cache;
	unordered_map<int, list<Entry>::iterator> map;
public:
	LRUCache(int capacity) {
		max_size = capacity;
	}

	int get(int key) {
		if (map.find(key) != map.end()) {
			movetofront(map[key]);
			return map[key]->value;
		}
		else
			return -1;
	}

	void set(int key, int value) {
		// If key exist,
		if (map.find(key) != map.end()) {
			map[key]->value = value;
			movetofront(map[key]);
		}
		//If key does not exist
		else {
			if (cache.size() < max_size) {
				cache.emplace(cache.begin(), Entry(key, value));
			}
			else {
				map.erase(cache.rbegin()->key);
				cache.erase(--cache.end());
				cache.emplace(cache.begin(), Entry(key, value));
			}
			map[key] = cache.begin();
		}
	}

	void movetofront(list<Entry>::iterator& it) {	//& can delete
		if (it != cache.begin())
			cache.splice(cache.begin(), cache, it);
	}
};

int main() {
	LRUCache cache(10);
	cache.set(1, 100);
	cache.set(2, 200);
	cache.set(1, 101);
	return 0;
}
