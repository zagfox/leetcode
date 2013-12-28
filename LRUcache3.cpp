#include <iostream>
#include <utility>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
	// Use pair, not so clear as using a class
private:
	int max_size;
	list<pair<int, int> > cache;
	unordered_map<int, list<pair<int, int> >::iterator> map;
public:
	LRUCache(int capacity):max_size(capacity) {}

	int get(int key) {
		if (map.find(key) != map.end()) {
			movetofront(map[key]);
			return map[key]->second;
		}
		else
			return -1;
	}

	void set(int key, int value) {
		// If key exist,
		if (map.find(key) != map.end()) {
			map[key]->second = value;
			movetofront(map[key]);
		}
		//If key does not exist
		else {
			if (cache.size() < max_size) {
				cache.emplace(cache.begin(), make_pair(key, value));
			}
			else {
				map.erase(cache.rbegin()->first);
				cache.erase(--cache.end());
				cache.emplace(cache.begin(), make_pair(key, value));
			}
			map[key] = cache.begin();
		}
	}

	void movetofront(list<pair<int, int> >::iterator& it) {	//& can delete
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
