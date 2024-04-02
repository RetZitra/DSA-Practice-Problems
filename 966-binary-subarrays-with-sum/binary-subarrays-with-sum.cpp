class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //tc=0(2n)+0(2n)=0(4n)
        //sc=0(1)
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt1=0;
        int cnt2=0;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            //sliding window take valid korchi jate kore sum ta goal range er moddhe thake
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            //valid korar por amra kokhonoi exactly sum==goal pabo na..jeheto goal take exceed
            //korte dicchi na tai subarray pete pari <=goal not exact goal ..after validation
            //of window
            cnt1+=(j-i+1);
            j++;
        }
        //jeheto exact sum=k pabo na tai subarrays with sum<=goal(cnt1) bar korchi..tarpr subarrays sum <=goal-1(cnt2)
        //bar korchi die cnt1-cnt2 korlei peye jacchi subarrays with sum exactly k
        i=0;
        j=0;
        sum=0;
        while(j<n){
            //edge case
            if(goal-1<0){
                cnt2=0;
                break;
            }
            sum+=nums[j];
            while(sum>(goal-1)){
                sum-=nums[i];
                i++;
            }
            cnt2+=(j-i+1);
            j++;
        }
        return (cnt1-cnt2);
    }
};