#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
public:
    vector<bool> exist;

    MyHashSet() {
        exist.resize(1000001, false);
    }
    
    void add(int key) {
        exist[key] = true;
    }
    
    void remove(int key) {
        exist[key] = false;
    }
    
    bool contains(int key) {
        return exist[key];
    }
};

int main()
{
    MyHashSet* myHashSet = new MyHashSet();
    myHashSet->add(1);
    myHashSet->add(2);
    cout << (myHashSet->contains(1) ? "true" : "false") << endl;
    cout << (myHashSet->contains(3) ? "true" : "false") << endl;
    myHashSet->add(2);
    cout << (myHashSet->contains(2) ? "true" : "false") << endl;
    myHashSet->remove(2);
    cout << (myHashSet->contains(2) ? "true" : "false") << endl;
    delete myHashSet;

    return 0;
}
