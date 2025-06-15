// Implement Queue using Stack (#232)

class MyQueue {
private:
    stack<int> inStack, outStack;

    // Move elements from inStack to outStack
    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transferIfNeeded();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transferIfNeeded();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};