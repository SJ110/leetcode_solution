/**
 中间栈遍历，取出最小。
 */

class SortedStack {
    stack<int> myStack;
    stack<int> stackHelper;
public:
    SortedStack() {

    }

    void push(int val) {
        myStack.push(val);
    }
    
    void pop() {
        if(myStack.empty()) {
            return;
        }
        int idx = 5001;
        while(!myStack.empty()) {
            int nowIdx = myStack.top();
            if(nowIdx < idx) idx = nowIdx;
            stackHelper.push(nowIdx);
            myStack.pop();
        }
        bool markPop = false;
        while(!stackHelper.empty()) {
            int nowIdx = stackHelper.top();
            if(markPop == true) {
                myStack.push(nowIdx);
                stackHelper.pop();
            } else {
                if(nowIdx == idx) {
                    markPop = true;
                    stackHelper.pop();
                } else {
                    myStack.push(nowIdx);
                    stackHelper.pop();
                }
            }
        }
    }
    
    int peek() {
        if(myStack.empty()) {
            return -1;
        }
        int idx = 5001;
        while(!myStack.empty()) {
            int nowIdx = myStack.top();
            if(nowIdx < idx) idx = nowIdx;
            stackHelper.push(nowIdx);
            myStack.pop();
        }
        while(!stackHelper.empty()) {
            int nowIdx = stackHelper.top();
            myStack.push(nowIdx);
            stackHelper.pop();
        }
        return idx;
    }
    
    bool isEmpty() {
        return myStack.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
