class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        // int cnt=0;
        //generating all the subarrays brute-force TC=0(n)
        // for(int i=0;i<n;i++){
        //     int oddcount=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]%2!=0){
        //             oddcount++;
        //         }
        //         if(oddcount==k){
        //             cnt++;
        //         }
        //         else if(oddcount>k){
        //             break;
        //         }
        //     }
        // }
        // return cnt;
        int cnt1=0;
        int cnt2=0;
        int i=0;
        int j=0;
        int oddcount=0;
        //finding the number of subarrays with odd number <=k
        while(j<n){
            if(nums[j]%2!=0){
                oddcount++;
            }
            while(oddcount>k){
                if(nums[i]%2!=0){
                    oddcount--;
                }
                i++;
            }
            cnt1+=(j-i+1);
            j++;
        }
        oddcount=0;
        i=0;
        j=0;
        //finding the number of subarrays with odd number <=(k-1)
        while(j<n){
            if(nums[j]%2!=0){
                oddcount++;
            }
            while(oddcount>(k-1)){
                if(nums[i]%2!=0){
                    oddcount--;
                }
                i++;
            }
            cnt2+=(j-i+1);
            j++;
        }
        return cnt1-cnt2;
    }
};