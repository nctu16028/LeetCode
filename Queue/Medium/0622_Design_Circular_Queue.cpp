#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    vector<int> buffer;
    int in, out;
    int capacity;

    MyCircularQueue(int k) {
        capacity = k + 1;
        buffer.resize(capacity, -1);
        in = 0;
        out = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        else
        {
            buffer[in] = value;
            in = (in + 1) % capacity;
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        else
        {
            buffer[out] = -1;
            out = (out + 1) % capacity;
            return true;
        }
    }
    
    int Front() {
        return buffer[out];
    }
    
    int Rear() {
        return buffer[(in + capacity - 1) % capacity];
    }
    
    bool isEmpty() {
        return (in == out);
    }
    
    bool isFull() {
        return ((in + 1) % capacity == out);
    }
};

int main()
{
    MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
    cout << (myCircularQueue->enQueue(1) ? "true" : "false") << endl;
    cout << (myCircularQueue->enQueue(2) ? "true" : "false") << endl;
    cout << (myCircularQueue->enQueue(3) ? "true" : "false") << endl;
    cout << (myCircularQueue->enQueue(4) ? "true" : "false") << endl;
    cout << myCircularQueue->Rear() << endl;
    cout << (myCircularQueue->isFull() ? "true" : "false") << endl;
    cout << (myCircularQueue->deQueue() ? "true" : "false") << endl;
    cout << (myCircularQueue->enQueue(4) ? "true" : "false") << endl;
    cout << myCircularQueue->Rear() << endl;
    delete myCircularQueue;

    return 0;
}
