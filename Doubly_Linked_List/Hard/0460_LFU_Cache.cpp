#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

struct CacheEntry {
    int key;
    int value;
    int counter;
    CacheEntry* next;   // represent head pointer if the instance is a list header
    CacheEntry* prev;   // represent tail pointer if the instance is a list header
    CacheEntry(int key, int val) : key(key), value(val), counter(1), next(nullptr), prev(nullptr) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        CacheEntry* oneHeader = new CacheEntry(-1, -1);     // use (key, value) = (-1, -1) to denote a list header
        freq2listHeader.insert({1, oneHeader});             // add a list header of counter 1
        size = 0;
        this->capacity = capacity;
    }

    ~LFUCache() {
        for (const auto& it : freq2listHeader)
        {
            // For each frequency number, delete the list header and its attaching list
            CacheEntry* head = it.second;
            while (head != nullptr)
            {
                CacheEntry* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }
    
    int get(int key) {
        if (key2ptr.find(key) == key2ptr.end())
            return -1;
        else
        {
            CacheEntry* target = key2ptr[key];
            promote(target);    // add 1 to its counter and move to "higher" list
            return target->value;
        }
    }
    
    void put(int key, int value) {
        if (key2ptr.find(key) == key2ptr.end())
        {
            if (size >= capacity)
                deleteAtLFU();
            insertNew(key, value);
        }
        else
        {
            CacheEntry* target = key2ptr[key];
            target->value = value;
            promote(target);    // add 1 to its counter and move to "higher" list
        }
    }

private:
    unordered_map<int, CacheEntry*> key2ptr;
    map<int, CacheEntry*> freq2listHeader;
    int size;
    int capacity;

    void promote(CacheEntry* target)
    {
        // Add new header if it does not exist
        if (freq2listHeader.find(target->counter + 1) == freq2listHeader.end())
        {
            CacheEntry* newHeader = new CacheEntry(-1, -1);
            newHeader->counter = target->counter + 1;
            freq2listHeader.insert({newHeader->counter, newHeader});
        }
        // Cut node
        if (target->prev == nullptr)
            freq2listHeader[target->counter]->next = target->next;
        else
            target->prev->next = target->next;
        if (target->next == nullptr)
            freq2listHeader[target->counter]->prev = target->prev;
        else
            target->next->prev = target->prev;
        // Paste node
        target->counter++;
        target->prev = nullptr;
        target->next = freq2listHeader[target->counter]->next;
        if (freq2listHeader[target->counter]->next == nullptr)
            freq2listHeader[target->counter]->prev = target;
        else
            freq2listHeader[target->counter]->next->prev = target;
        freq2listHeader[target->counter]->next = target;
    }

    void insertNew(int key, int value)
    {
        CacheEntry* temp = new CacheEntry(key, value);
        temp->next = freq2listHeader[1]->next;
        if (freq2listHeader[1]->next == nullptr)
            freq2listHeader[1]->prev = temp;
        else
            freq2listHeader[1]->next->prev = temp;
        freq2listHeader[1]->next = temp;
        key2ptr.insert({key, temp});
        size++;
    }

    void deleteAtLFU()
    {
        int minFreq;
        for (const auto& it : freq2listHeader)
        {
            if (it.second->prev != nullptr)
            {
                minFreq = it.first;
                break;
            }
        }
        CacheEntry* toDelete = freq2listHeader[minFreq]->prev;
        if (toDelete->prev == nullptr)
            freq2listHeader[minFreq]->next = nullptr;
        else
            toDelete->prev->next = nullptr;
        freq2listHeader[minFreq]->prev = toDelete->prev;
        key2ptr.erase(toDelete->key);
        delete toDelete;
        size--;
    }
};

int main()
{
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1, 1);
    lfu->put(2, 2);
    cout << lfu->get(1) << endl;
    lfu->put(3, 3);
    cout << lfu->get(2) << endl;
    cout << lfu->get(3) << endl;
    lfu->put(4, 4);
    cout << lfu->get(1) << endl;
    cout << lfu->get(3) << endl;
    cout << lfu->get(4) << endl;
    delete lfu;

    return 0;
}
