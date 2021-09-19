/**
 另起一个栈保存当前栈内的最小值
 */
class MinStack {
    stack<int> stack1;
    stack<int> stackHelper;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stack1.push(x);
        if(stackHelper.empty()) {
            stackHelper.push(x);
        } else if(x <= stackHelper.top()) {
            stackHelper.push(x);
        }
    }
    
    void pop() {
        if(!stack1.empty()) {
            int top = stack1.top();
            stack1.pop();
            if(!stackHelper.empty() && top == stackHelper.top()) {
                stackHelper.pop();
            }
        }
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stackHelper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
