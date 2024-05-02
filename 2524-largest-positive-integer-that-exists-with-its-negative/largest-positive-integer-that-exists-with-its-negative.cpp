class Solution {
public:
//sort kore nebo die tar left side e -element gulo thakbe ar right side e +ve element gulo thakbe
//die greedly right side theke je boro dekhbo je tar -ve ta present kina jodi hoi to return korbo
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        //loop ta cholbe jotokhon i pointer ta -ve er range e thkebe
        //thelei sob negetive number er joono tar positive ta ache kina check hoi jabe
        while(nums[i]<0 && i<j){
            if((nums[i]*-1)==nums[j]){
                return nums[j];
            }
            //jodi je boro seta current -ve jeta tar positive value er cheye boro hoi to nums[j] number ta choto nebar chesta korbo
            else if((nums[i]*-1)<nums[j]){
                j--;
            }
            //jodi je -ve number tar positive ta current postive number(nums[j]) er cheye boro hoi to nums[i] take choto nebar chesta korbo  
            else{
                i++;
            }
        }
        return -1;
    }
};