class Solution {
public:
    void dfs(int node,int dist,vector<int>adj[],vector<int> &pathvis,vector<int> &vis,vector<int> &dist_v,int& ans){
        vis[node]=1;
        pathvis[node]=1;
        dist_v[node]=dist;
        for(auto it:adj[node]){
        if(it!=-1){
            if(!vis[it]){
                dfs(it,dist+1,adj,pathvis,vis,dist_v,ans);
            }
            //while ditecting cycle
            else if(pathvis[it]){
               ans=max(ans,(dist+1)-dist_v[it]);
            }
        }
        }
        pathvis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        //n is the number of nodes
        int ans=-1;
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            adj[i].push_back(edges[i]);
        }
        vector<int>pathvis(n,0);
        vector<int>vis(n,0);
        vector<int>dist_v(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,0,adj,pathvis,vis,dist_v,ans);
            }
        }
        return ans;
    }
};