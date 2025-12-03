#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> vals;
    stack<int> min_vals;

    MinStack() {
        
    }
    
    void push(int val) {
        vals.push(val);
        if (min_vals.empty() || val <= min_vals.top())
            min_vals.push(val);
    }
    
    void pop() {
        if (!min_vals.empty() && vals.top() == min_vals.top())
            min_vals.pop();
        vals.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return min_vals.top();
    }
};

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;     // return -3
    minStack->pop();
    cout << minStack->top() << endl;        // return 0
    cout << minStack->getMin() << endl;     // return -2

    return 0;
}
