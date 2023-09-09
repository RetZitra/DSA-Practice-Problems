class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses;
        int e=prerequisites.size();
        vector<int>adj[v];
        int c=0;
        queue<int>q;
        for(int i=0;i<e;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        int indegree[v];
        for(int i=0;i<v;i++){
            indegree[i]=0;
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
            c++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(c==v){
           return true;
        }
        return false;
    }
};