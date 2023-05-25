#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> frontEnd;
    stack<int> backEnd;

    MyQueue() {
        
    }
    
    void push(int x) {
        backEnd.push(x);
    }
    
    int pop() {
        if (frontEnd.empty())
        {
            while (!backEnd.empty())
            {
                frontEnd.push(backEnd.top());
                backEnd.pop();
            }
        }
        int output = frontEnd.top();
        frontEnd.pop();
        return output;
    }
    
    int peek() {
        if (frontEnd.empty())
        {
            while (!backEnd.empty())
            {
                frontEnd.push(backEnd.top());
                backEnd.pop();
            }
        }
        return frontEnd.top();
    }
    
    bool empty() {
        return frontEnd.empty() && backEnd.empty();
    }
};

int main()
{
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1);
    myQueue->push(2);
    cout << myQueue->peek() << endl;
    cout << myQueue->pop() << endl;
    cout << (myQueue->empty() ? "true" : "false") << endl;
    delete myQueue;

    return 0;
}
