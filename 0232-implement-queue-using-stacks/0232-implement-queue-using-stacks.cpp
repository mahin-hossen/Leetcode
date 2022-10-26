class MyQueue {
public:
    stack<int> input, output; //input reveresd/output ordered
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);        
    }
    
    int pop() {
        int num = peek();
        output.pop();
        return num;
    }
    
    int peek() {
        //5 4 3 2 1 //in
        //1 2 3 4 5 //out
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();        
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */