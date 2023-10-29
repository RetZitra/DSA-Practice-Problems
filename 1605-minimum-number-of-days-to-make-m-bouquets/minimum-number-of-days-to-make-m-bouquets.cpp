class Solution {
public:
    int maxelement(vector<int>&bloomDay){
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            if(maxi<bloomDay[i]){
                maxi=bloomDay[i];
            }
        }
        return maxi;
    }
      int minelement(vector<int>&bloomDay){
        int mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            if(mini>bloomDay[i]){
                mini=bloomDay[i];
            }
        }
        return mini;
    }
    int makebouquets(vector<int>& bloomDay,int waitday,int k){
       int current_f=0;
       int totalb=0;
       for(int i=0;i<(bloomDay.size());i++){
           if(waitday>=bloomDay[i]){
               current_f+=1;
           }

           else{
               totalb+=(current_f/k);
               current_f=0;
           }
       }
       if(current_f!=0){
           totalb+=(current_f/k);
       }
       return totalb;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>(long long)bloomDay.size()){
            return -1;
        }
        int low=minelement(bloomDay);
        int high=maxelement(bloomDay);
        int ans=0;
        while(low<=high){
            int mid=(low+((high-low)/2));
            int bouquets_no_of_the_day=makebouquets(bloomDay,mid,k);
            if(bouquets_no_of_the_day>=m){
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