class Solution {
public:
    //ei problem tai basically directed graph er edge gulo die dieche..
    //to amk findout korte hobe,je jodi toposort kora jai mane graph ta cyclic na hoi thle true return korte 
    //ar jodi toposort kora na jai mane graph ta cyclic hoi..thle false return korte
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //numcourse ta holo number of course
        int v=numCourses;
        int e=prerequisites.size();
        vector<int>adj[v];
        int c=0;
        queue<int>q;
        //adjacency list banie nicchi
        //ekhane boleche jeta second e deoa thekbe seta first e asbe to v->u ta deoa ache tai sei vhabe adjacency list
        //ta banalam
        for(int i=0;i<e;i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
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