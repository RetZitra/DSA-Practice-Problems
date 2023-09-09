class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses;
        int e=prerequisites.size();
        vector<int>adj[v];
        int indegree[v];
        vector<int>ans;
        queue<int>q;
        int cnt=0;
        for(int i=0;i<v;i++){
            indegree[i]=0;
        }
        for(int i=0;i<e;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            cnt++;
            for(auto it:adj[node]){
               indegree[it]--;
               if(indegree[it]==0){
                   q.push(it);
               }
            }
        }
        reverse(ans.begin(),ans.end());
        if(cnt==v){
            return ans;
        }
        ans.clear();
        return ans;
    }
};