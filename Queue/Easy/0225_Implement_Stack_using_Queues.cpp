#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        int output = q.front();
        q.pop();
        return output;
    }
    
    int top() {
        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        int output = q.front();
        q.push(output);
        q.pop();
        return output;
    }
    
    bool empty() {
        return q.empty();
    }
};

int main()
{
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    cout << myStack->top() << endl;
    cout << myStack->pop() << endl;
    cout << (myStack->empty() ? "true" : "false") << endl;
    delete myStack;

    return 0;
}
