#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        else if (cache.size() == capacity) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }

    void display() {
        for (auto x : cache)
            cout << x.first << ":" << x.second << " ";
        cout << endl;
    }
};

int main() {
    LRUCache lru(3);

    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);

    lru.get(1);
    lru.put(4, 40);

    lru.display();

    return 0;
}
