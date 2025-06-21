class Solution {
public:
    set<int> vis;

    void dfs(vector<vector<int>>& isConnected , int node){

        if(vis.find(node) != vis.end())return;
        vis.insert(node);

        for(int i = 0 ; i < isConnected[node].size() ; i++){
            if(isConnected[node][i] == 1 && vis.find(i) == vis.end()){
                dfs(isConnected , i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
    int count = 0;
        vis.clear();
        for(int i = 0 ; i < isConnected.size() ; i++){
                if(vis.find(i)  == vis.end()){
                    count++;
                    dfs(isConnected , i);
                }
        }
        return count;
    }
};