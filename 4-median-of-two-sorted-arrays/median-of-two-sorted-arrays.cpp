class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.insert(merged.end(),nums1.begin(),nums1.end());
        merged.insert(merged.end(),nums2.begin(),nums2.end());
        sort(merged.begin(),merged.end());
        int start=0;
        int end=merged.size()-1;
        int index=((start+end)/2);
        int n=merged.size();
        if(n%2!=0){
            return merged[index];
        }
        else{
            int index2=index+1;
            return ((merged[index]+merged[index2])/2.0);
        }
    
    }
};