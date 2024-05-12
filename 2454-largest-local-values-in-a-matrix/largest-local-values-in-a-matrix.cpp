class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        //protita column er jonno 3 line er range fixed kore nicche r1..jota valid range hoi
        //ar oi column er respect e 3 line er range fixed kore nicche r2 jota valid range hoi
        //die protita valid range er row column er jonno protia point traverse korche i,j
        //die tar max ta store kore oi range er (r1,r2) te value ta bosache
        for(int r1=0;r1+2<n;r1++){
            for(int r2=0;r2+2<n;r2++){
                int maxi=INT_MIN;
                for(int i=r1;i<=r1+2;i++){
                    for(int j=r2;j<=r2+2;j++){
                        maxi=max(grid[i][j],maxi);
                    }
                }
                 ans[r1][r2]=maxi;
            }
        }
        return ans;
    }
};