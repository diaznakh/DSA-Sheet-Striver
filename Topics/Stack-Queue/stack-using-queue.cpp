class MyStack {
public:
    // Constructor
    MyStack() {
        // No initialization required as we're using STL queue
    }

    // Push element x onto stack
    void push(int x) {
        temporaryQueue.push(x);
      
        // Reverse the order of elements by moving everything from mainQueue to temporaryQueue
        while (!mainQueue.empty()) {
            temporaryQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        // Swap the names of mainQueue and temporaryQueue to reflect the change
        swap(mainQueue, temporaryQueue);
    }

    // Removes the element on top of the stack and returns that element
    int pop() {
        int topElement = mainQueue.front(); // Get the top element
        mainQueue.pop(); // Remove the top element from the queue
        return topElement; // Return the popped element
    }

    // Get the top element of the stack
    int top() {
        return mainQueue.front(); // The front of mainQueue is the top of stack
    }

    // Returns true if the stack is empty, false otherwise
    bool empty() {
        return mainQueue.empty(); // Check if the mainQueue is empty
    }

private:
    queue<int> mainQueue;     // This will act as the stack
    queue<int> temporaryQueue; // Used to reverse the order of elements in push operation
};