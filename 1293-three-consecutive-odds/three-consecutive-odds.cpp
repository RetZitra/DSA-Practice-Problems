class Solution {
public:
//to track consecutive we use a variable called count
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        //odd hote thakle cnt take increase korchi ar even hole cnt ta reset hocche to jodi por por 3 te consecutive odd hoi mne cnt ta jodi kono somoy 3 hoi to 
        //return true hobe,ar puro array ta traverse hoi geleo jodi kono somoy cnt 3 na hoi mane 3 bar consecutive odds hocche na to sesh e return false hocche
        for(int i=0;i<n;i++){
           if(arr[i]%2!=0){
            cnt++;
           }
           else{
            cnt=0;
           }
           if(cnt==3){
            return true;
           }
        }
        return false;
    }
};