class MinStack {
public:
    vector<pair<int,int>>nums;
    MinStack() {}
    
    void push(int val) {

        int min_val = getMin();

        if(nums.empty() || min_val > val) min_val = val;

        nums.push_back({val, min_val});
        
    }
    
    void pop() {

        nums.pop_back();
        
    }
    
    int top() {

        if(nums.empty()) return -1;
        else return nums.back().first;
        
    }
    
    int getMin() {

        if(nums.empty()) return -1;

        return nums.back().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */