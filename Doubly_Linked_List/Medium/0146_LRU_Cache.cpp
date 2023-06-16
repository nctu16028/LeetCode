#include <iostream>
#include <unordered_map>
using namespace std;

struct CacheEntry {
    int key;
    int value;
    CacheEntry* next;
    CacheEntry* prev;
    CacheEntry(int key, int val) : key(key), value(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = nullptr;     // most-recently-used side
        tail = nullptr;     // least-recently-used side
        size = 0;
        this->capacity = capacity;
    }

    ~LRUCache() {
        while (head != nullptr)
        {
            CacheEntry* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int get(int key) {
        if (key2ptr.find(key) == key2ptr.end())
            return -1;
        else
        {
            CacheEntry* target = key2ptr[key];
            moveToMRU(target);
            return target->value;
        }
    }
    
    void put(int key, int value) {
        if (key2ptr.find(key) == key2ptr.end())
        {
            if (size >= capacity)
                deleteAtLRU();
            insertAtMRU(key, value);
        }
        else
        {
            CacheEntry* target = key2ptr[key];
            target->value = value;
            moveToMRU(target);
        }
    }

private:
    unordered_map<int, CacheEntry*> key2ptr;
    CacheEntry* head;
    CacheEntry* tail;
    int size;
    int capacity;

    void moveToMRU(CacheEntry* target)
    {
        if (target != head)
        {
            target->prev->next = target->next;
            if (target == tail)
                tail = target->prev;
            else
                target->next->prev = target->prev;
            target->next = head;
            target->prev = nullptr;
            head->prev = target;
            head = target;
        }
    }

    void insertAtMRU(int key, int value)
    {
        CacheEntry* temp = new CacheEntry(key, value);
        temp->next = head;
        if (head == nullptr)
            tail = temp;
        else
            head->prev = temp;
        head = temp;
        key2ptr.insert({key, temp});
        size++;
    }

    void deleteAtLRU()
    {
        CacheEntry* toDelete = tail;
        tail = tail->prev;
        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;
        key2ptr.erase(toDelete->key);
        delete toDelete;
        size--;
    }
};

int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);
    lRUCache->put(2, 2);
    cout << lRUCache->get(1) << endl;
    lRUCache->put(3, 3);
    cout << lRUCache->get(2) << endl;
    lRUCache->put(4, 4);
    cout << lRUCache->get(1) << endl;
    cout << lRUCache->get(3) << endl;
    cout << lRUCache->get(4) << endl;
    delete lRUCache;

    return 0;
}
