#include <stack>

class MyQueue {
private:
    std::stack<int> mainStack;
    std::stack<int> tempStack;

public:
    MyQueue() {

    }

    void push(int x) {
        mainStack.push(x);
    }

    int pop() {
        while (!mainStack.empty()) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }

        int top = tempStack.top();
        tempStack.pop();

        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        return top;
    }

    int peek() {
        while (!mainStack.empty()) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }

        int top = tempStack.top();

        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        return top;
    }

    bool empty() {
        return mainStack.empty();
    }
};