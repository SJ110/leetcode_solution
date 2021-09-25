/**
 从target向start寻找，才不会超时
 */
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(n < (target+1)) {
            return false;
        }
         return findWayExsitHelper2(graph,start,target);

        //return findWayExsitHelper(graph,start,target);
    }

private:
    bool findWayExsitHelper2(vector<vector<int>>& graph,int start,int target) {
        for(int i = 0; i<graph.size();i++){
            vector<int> idx = graph[i];
            if(idx[1] == target) {
                if(idx[0] == start) {
                    return true;
                }
                if(idx[0] != idx[1]) {
                    int ret = findWayExsitHelper2(graph,start,idx[0]);
                    if(ret) return ret;
                }
            }
        }
        return false;
    }


    bool findWayExsitHelper(vector<vector<int>>& graph, int start,int target) {
        for(int i = 0; i<graph.size();i++){
            vector<int> idx = graph[i];
            if(idx[0] == start) {
                if(idx[1] == target) {
                    return true;
                }
                if(idx[0] != idx[1]) {
                    int ret = findWayExsitHelper(graph,idx[1],target);
                    if(ret) return ret;
                }
            }
            if(idx[0] > start) {
                break;
            }
        }
        return false;
    }
};
