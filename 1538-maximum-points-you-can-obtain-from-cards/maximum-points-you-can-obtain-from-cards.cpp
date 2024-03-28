class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        for(int i=0;i<k;i++){
           lsum+=cardPoints[i];
        }
        if(n==k){
            return lsum;
        }
        int rsum=0;
        int maxi=lsum;
        int i=k-1;
        int j=n;
        while(k>0){
            if(i>=0){
                lsum-=cardPoints[i];
                
            }
            i--;
            j--;
            rsum+=cardPoints[j];
            maxi=max(maxi,(lsum+rsum));
            k--;
        }
        return maxi;
    }
};