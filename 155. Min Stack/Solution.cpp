class MinStack {
public:
    stack<int>s;
    stack<int>MS;
    MinStack() {
        
    }
    void push(int value) {
        this->s.push(value);
        if(this->MS.empty()){
            this->MS.push(value);
        }
        else{
            if(this->MS.top()>=value){
                this->MS.push(value);
            }
        }
    }
    
    void pop() {
        int num = this->s.top();
        s.pop();
        if(num == this->MS.top()){
            this->MS.pop();
        }
    }
    
    int top() {
        return this->s.top();
    }
    
    int getMin() {
        return this->MS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */