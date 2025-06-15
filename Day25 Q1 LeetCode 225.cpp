// Implement Stack using Queues (#225)

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        // Move all from q1 to q2 so the new element is at front
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap names so q1 always has the stack order
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};