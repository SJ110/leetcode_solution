/**
 思路比较简单，就是一个简单的递归，判断是列表继续执行，判断是数字返回，
 关键是找到判断是否是数字的方法，isInteger  迭代器转化数字的方法getInteger
 */

class NestedIterator {
    private:
    vector<int> retArray;
    int index;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        dfs(nestedList);
    }
    
    int next() {
        return retArray[index++];
    }
    
    bool hasNext() {
        if(index <retArray.size()) {
            return true;
        }else {
            return false;
        }
    }
    void dfs(vector<NestedInteger> &nestedList) {
        for (auto tmpArray: nestedList) {
            if(tmpArray.isInteger()) {
                retArray.push_back(tmpArray.getInteger());
            }else {
                dfs(tmpArray.getList());
            }
        }
    }

};
