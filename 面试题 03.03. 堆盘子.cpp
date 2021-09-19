/**
 考虑栈大小为0的场景，vector.size()-1可能报错，因为vector.size()返回unsigned int
 */
class StackOfPlates {
    vector<stack<int>> stackPlates;
    int size;
public:
    StackOfPlates(int cap) {
        size = cap;
    }
    
    void push(int val) {
        if(size <= 0) return;
        if(stackPlates.size() == 0) {
            stack<int> tmpStack;
            tmpStack.push(val);
            stackPlates.push_back(tmpStack);
        } else {
            stack<int> tmpStack = stackPlates.back();
            if (tmpStack.size() >= size) {
                stack<int> newTmpStack;
                newTmpStack.push(val);
                stackPlates.push_back(newTmpStack);
            } else {
                tmpStack.push(val);
                stackPlates[stackPlates.size()-1] = tmpStack;
            }
        }
    }
    
    int pop() {
        if(size <= 0) return -1;
        if(stackPlates.size()==0) return -1;
        stack<int> tmp = stackPlates.back();
        int ret = tmp.top();
        tmp.pop();
        if(tmp.empty()) {
            stackPlates.pop_back();
        } else {
            stackPlates[stackPlates.size()-1] = tmp;
        }
        return ret;
    }
    
    int popAt(int index) {
        if((index + 1) > stackPlates.size()) return -1;
        stack<int> tmpStack = stackPlates[index];
        int ret = tmpStack.top();
        tmpStack.pop();
        if(tmpStack.empty()) {
            stackPlates.erase(stackPlates.begin()+index);
        } else {
            stackPlates[index] = tmpStack;
        }
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
