#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    const int NUM_BUCKETS = 1024;
    vector<vector<pair<int, int>>> buckets;

    MyHashMap() {
        buckets.resize(NUM_BUCKETS, vector<pair<int, int>>());
    }
    
    void put(int key, int value) {
        int idx = key % NUM_BUCKETS;
        for (auto& it : buckets[idx])
        {
            if (key == it.first)
            {
                it.second = value;
                return;
            }
        }
        buckets[idx].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int idx = key % NUM_BUCKETS;
        for (auto& it : buckets[idx])
        {
            if (key == it.first)
                return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = key % NUM_BUCKETS;
        for (auto it = buckets[idx].begin(); it != buckets[idx].end(); it++)
        {
            if (key == it->first)
            {
                buckets[idx].erase(it);
                return;
            }
        }
    }
};

int main()
{
    MyHashMap* myHashMap = new MyHashMap();
    myHashMap->put(1, 1);
    myHashMap->put(2, 2);
    cout << myHashMap->get(1) << endl;
    cout << myHashMap->get(3) << endl;
    myHashMap->put(2, 1);
    cout << myHashMap->get(2) << endl;
    myHashMap->remove(2);
    cout << myHashMap->get(2) << endl;
    delete myHashMap;

    return 0;
}
