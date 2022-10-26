class MyQueue {
public:
    /// 1 2 3 4 5
    /// 
    /// 5 4 3 2
    /// 2 3 4 5
    stack<int> main, aux;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        while(!main.empty())//main->aux(reversed)
        {
            aux.push(main.top());
            main.pop();
        }
        aux.push(x);
        while(!aux.empty())
        {
            main.push(aux.top());
            aux.pop();
        }
    }
    
    int pop()
    {
        int num = main.top();
        main.pop();
        return num;
    }
    
    int peek() 
    {
        return main.top();
    }
    
    bool empty() 
    {
        return main.empty();
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