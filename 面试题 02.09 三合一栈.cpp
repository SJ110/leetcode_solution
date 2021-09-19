/**
前stakSize*3作为栈，后3个作为容量
 */

class TripleInOne {
    vector<int> mystack;
    int size;
    int allSize;
public:
    TripleInOne(int stackSize) {
        size = stackSize;
        for(int i = 0;i<(stackSize * 3 + 3);i++) {
            mystack.push_back(-1);
        }
        allSize = stackSize * 3 + 3;
        mystack[allSize - 1] = mystack[allSize - 2] = mystack[allSize -3] = 0;
    }
    
    void push(int stackNum, int value) {
        int nowSize = mystack[allSize - stackNum - 1];
        if(nowSize >= size)
            return;
        mystack[size * stackNum + nowSize] = value;
        mystack[allSize - stackNum - 1]++;
    }
    
    int pop(int stackNum) {
        int nowSize = mystack[allSize - stackNum - 1];
        if(nowSize == 0) return -1;
        int ret = mystack[stackNum*size + nowSize-1];
        mystack[allSize - stackNum - 1]--;
        return ret;
    }
    
    int peek(int stackNum) {
        int nowSize = mystack[allSize - stackNum - 1];
        if(nowSize == 0) return -1;
        return mystack[stackNum*size+nowSize-1];
    }
    
    bool isEmpty(int stackNum) {
        return mystack[allSize - stackNum - 1] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
