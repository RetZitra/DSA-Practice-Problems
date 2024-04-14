class Solution {
public:
//source node theke current node e minimum koto distance e jete parchi(dijsktra)+additionally bole dieche jodi disappear er age na jete pari reach kora jabe na
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n,1e9);
        vector<int>ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int node=it.second;
            //0th node theke oi node er distance
            int dis=it.first;
            //oi node er adjacent gulo visit korchi
            //jodi current node tar distance...ager calculate kora distance er theke boro hoi to oi node take ar process korchi na
            if(dis>dist[node]){
                continue;
            }
            for(auto it2:adj[node]){
                int adjnode=it2.first;
                //current node theke adjnode er distence
                int dis2=it2.second;
                if(dis+dis2<dist[adjnode] && dis+dis2<disappear[adjnode]){
                    dist[adjnode]=dis+dis2;
                    //0 theke oi node e aste dis+dis2 distance lagche + oi node ta visit holo to tar adjacent node ta pore visit hobe
                    q.push({dis+dis2,adjnode});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]!=1e9){
                ans[i]=dist[i];
            }
            else{
                ans[i]=-1;
            }
        }
        return ans;
        
    }
};