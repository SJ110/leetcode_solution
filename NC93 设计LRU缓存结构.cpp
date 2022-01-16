class Solution {
    vector<vector<int>> LRUVec;
    int size;
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> retVec;
        if (k == 0) return retVec;
        size = k;
        for(int i = 0; i< operators.size();i++) {
            vector<int> tmp = operators[i];
            if (tmp[0] == 1) {
                setLRU(tmp);
            } else {
                retVec.push_back(getLRU(tmp));
            }
        }
        return retVec;
    }
    
    void setLRU(vector<int> params) {
        vector<int> node = {params[1],params[2]};
        if(LRUVec.size() == size) {
            removeLRU();
        }
        LRUVec.push_back(node);
    }
    
    int getLRU(vector<int> params) {
        int index = -1;
        int ret = -1;
        for(int i = LRUVec.size()-1 ;i>=0;i--) {
            if (LRUVec[i][0] == params[1]) {
                index = i;
                ret = LRUVec[i][1];
//                 cout << ret << "+++"<<index<<"\n";
                break;
            }
        }
        if (ret != -1) {
            vector<int> tmp = LRUVec[index];
            for(int i=index;i<LRUVec.size()-1;i++) {
               LRUVec[i] = LRUVec[i+1];
            }
            LRUVec[LRUVec.size() - 1] = tmp;
        }
        return ret;
    }
    
    void removeLRU() {
        for(int i = 0;i < (size-1); i++) {
            LRUVec[i] = LRUVec[i+1];
        }
        LRUVec.pop_back();
    }
};
