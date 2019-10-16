#include<list>
std::list<int> deq;
std::unordered_map<int, list<int>::iterator> myMap;
std:unordered_map<int, int> valMap;
int cacheSize;
    
LRUCache::LRUCache(int capacity) {
    cacheSize = capacity;
    deq.clear();
    valMap.clear();
    myMap.clear();
}

int LRUCache::get(int key) {
    if(myMap.find(key) != myMap.end()) {
        return valMap[key];
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(myMap.find(key) != myMap.end()) {
        deq.erase(myMap[key]);
        valMap[key] = value;
    }
    else if(deq.size() == cacheSize) {
        //Remove LRU
        int last = deq.back();
        myMap.erase(last);
        deq.pop_back();
    }

    deq.push_front(key);
    valMap[key] = value;
    myMap[key] = deq.begin();
}
