class MyQueue {
    public:
        MyQueue() {}
    
        void push(int x) {
            mainStack.push(x);
        }
    
        int pop() {
            if(!temporaryStack.empty()){
                int pop = temporaryStack.top();
                temporaryStack.pop();
    
                return pop;
            }else
                while(mainStack.size()){
                    temporaryStack.push(mainStack.top());
                    mainStack.pop();
                }
                int pop = temporaryStack.top();
                temporaryStack.pop();
    
                return pop;
            
        }
    
        int peek() {
            if(!temporaryStack.empty()){
                return temporaryStack.top();
            }else
            while(mainStack.size()){
                    temporaryStack.push(mainStack.top());
                    mainStack.pop();
                }
    
                return temporaryStack.top();
        }
    
        bool empty() {
            return mainStack.empty() && temporaryStack.empty();
        }
    
    private:
        stack<int> mainStack;
        stack<int> temporaryStack;
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */