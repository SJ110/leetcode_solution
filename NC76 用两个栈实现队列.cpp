class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack1.empty()) {
            return -1;
        }
        popHelper();
        int ret = stack2.top();
        pushHelper();
        return ret;
    }
    
    void popHelper() {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    void pushHelper() {
        if (!stack2.empty()) {
            stack2.pop();
        }
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

private:
    stack<int> stack1; /// head
    stack<int> stack2; /// tail
};
