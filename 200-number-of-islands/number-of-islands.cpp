class Solution {
private:
void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int delrow[],int delcol[],int n,int m){
    vis[row][col]=1;
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && (!vis[nrow][ncol]) && (grid[nrow][ncol]=='1')){
            dfs(nrow,ncol,grid,vis,delrow,delcol,n,m);
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        for(int j=0;j<m;j++){
            if((!vis[0][j]) && (grid[0][j]=='1')){
                dfs(0,j,grid,vis,delrow,delcol,n,m);
                count++;
            }
            if((!vis[n-1][j]) && (grid[n-1][j]=='1')){
                dfs(n-1,j,grid,vis,delrow,delcol,n,m);
                count++;
            }
        }
          for(int i=0;i<n;i++){
            if((!vis[i][0]) && (grid[i][0]=='1')){
                dfs(i,0,grid,vis,delrow,delcol,n,m);
                count++;
            }
            if((!vis[i][m-1]) && (grid[i][m-1]=='1')){
                dfs(i,m-1,grid,vis,delrow,delcol,n,m);
                count++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((vis[i][j]==0) && (grid[i][j]=='1')){
                    dfs(i,j,grid,vis,delrow,delcol,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};