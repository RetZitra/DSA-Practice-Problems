class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>adjrev[v];
        int indegree[v];
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<v;i++){
            indegree[i]=0;
        }
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int safenode=q.front();
            q.pop();
            ans.push_back(safenode);
            for(auto it:adjrev[safenode]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};