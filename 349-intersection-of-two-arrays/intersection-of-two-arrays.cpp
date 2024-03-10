class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        int prev=-1;
        int i=0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n1 && j<n2){
            //jodi jekono akta array traverse hoa sesh hoi jai thle setake compare korar jonno tar last element take point korabo
            //jai array ta age traverse kora hoi jacche seta basically tar last index ke point korche jotokhon na onno array ta traverse sesh hoi
            if(nums1[i]==nums2[j]){
                //jodi equal hoi to push korar age dekhe nebo je seta vector e present chilo kina
                //karon dublicate allow nei
                if(nums1[i]!=prev){
                    ans.push_back(nums1[i]);
                    prev=nums1[i];
                }
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                //jeheto array gulo sorted tai jodi nums1 er element ta boro hoi thle nums2 er porer element tai gie dekhbo je element gulo equal hocche kina 
                j++;
            }
            else{
                //jeheto array gulo sorted tai jodi nums2 er element ta boro hoi thle nums1 er porer element tai gie dekhbo je element gulo equal hocche kina
                i++;
            }
        }
        return ans;
    }
};