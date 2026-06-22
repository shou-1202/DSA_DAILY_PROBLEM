class MyStack {
public:
    queue<int>front;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = this->front.size();
        this->front.push(x);

        for(int i = 0; i<size;i++){
            int a = this->front.front();
            this->front.pop();
            this->front.push(a);
        }
    }
    
    int pop() {
        int x = this->front.front();
        this->front.pop();
        return x;
    }
    
    int top() {
        return this->front.front();
    }
    
    bool empty() {
        if(this->front.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */