class Solution {
public:
    int maxelement(vector<int>&piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(maxi<piles[i]){
                maxi=piles[i];
            }
        }
        return maxi;
    }
    double totalhrs(vector<int>&piles ,int hourly){
        int n=piles.size();
        double thours=0;
        //if we dont do type cast it take int value which is take floor value ,but our motive is to take ceil value so for that we need to keep decimal points thats what we have to type cast
        for(int i=0;i<n;i++){
            thours+=ceil((double)piles[i]/(double)hourly);
        }
        return thours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=maxelement(piles);
        while(low<=high){
        int sum=0;
        int mid=(low+((high-low))/2);
           double hrs=totalhrs(piles,mid);
           if(hrs<=h){
               high=mid-1;
               
           }
           else{
               low=mid+1;
           }
        }
        return low;
    }
};