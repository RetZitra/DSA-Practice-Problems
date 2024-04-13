class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int>x;
        for(auto it:points){
            x.push_back(it[0]);
        }
        sort(x.begin(),x.end());
        int n=x.size();
        //edge case
        if(n==1){
            return 1;
        }
        int maxx=x[n-1];
        int count=0;
        int dist=-1;
        for(int i=0;i<n;i++){
            while(i<n && x[i]<=dist){
                i++;
            }
            if(i>=n){
                break;
            }
            dist=(x[i]+w);
            count++;
        }
        return count;
        
    }
};