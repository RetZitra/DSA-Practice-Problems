class Solution {
public:
        int maxelement(vector<int>&weights){
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            if(maxi<weights[i]){
                maxi=weights[i];
            }
        }
        return maxi;
    }
    int all_sum(vector<int>&weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    }
    int totaldays(vector<int>&weights,int days){
         int sum=0;
         int day=0;
         for(int i=0;i<weights.size();i++){
             if(sum+weights[i]<=days){
                 sum+=weights[i];
             }
             else{
                 day+=1;
                 sum=weights[i];
             }
         }
         if(sum!=0){
             day++;
         }
         return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=maxelement(weights);
        int high=all_sum(weights);
        int ans;
        while(low<=high){
            int mid=(low+((high-low)/2));
            int pdays=totaldays(weights,mid);
            if(pdays<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
   
};