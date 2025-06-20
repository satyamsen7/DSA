#include <iostream>
#include <stack>

class QueueUsingTwoStacks {
private:
    std::stack<int> enqueueStack;
    std::stack<int> dequeueStack;

public:
    void enqueue(int data) {
        enqueueStack.push(data);
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        int front = dequeueStack.top();
        dequeueStack.pop();
        return front;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        return dequeueStack.top();
    }

    bool isEmpty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }

    int size() {
        return enqueueStack.size() + dequeueStack.size();
    }
};