class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //accessing each element using 2 nasted loop then check if it is the minimum element of it's row and maximum element of it's column 
                int maxi=INT_MIN;
                int mini=INT_MAX;
                //column wise traversal based on an element
                for(int col=0;col<n;col++){
                    maxi=max(maxi,matrix[col][j]);
                }
                //row wise traversal based on an element
                for(int row=0;row<m;row++){
                    mini=min(mini,matrix[i][row]);
                }
                //if a element is minimum of its row and maximum of its column the it is conciderd as lucky number
                if(mini==matrix[i][j] && maxi==matrix[i][j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};