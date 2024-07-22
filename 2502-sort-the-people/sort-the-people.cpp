class Solution {
public:
//total tc=O(2n)
//total sc=O(n)
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //sc=O(n)
        //these vector of pair store each people height with there index
        vector<pair<int,int>>index_heights;
        vector<string>ans;
        int n=heights.size();
        //tc=O(n)
        for(int i=0;i<n;i++){
            index_heights.push_back({heights[i],i});
        }
        //sort heights with tracking to its index,so that each man's height is not change with respect to it's index
        //we have to access the height in decending order,so sort custom height array in ascending order and access them back to front so it's became decending order
        sort(index_heights.begin(),index_heights.end());
        //according to the height in decending order print the names of the people
        //tc=O(n)
        for(int i=n-1;i>=0;i--){
            ans.push_back(names[index_heights[i].second]);
        }
        return ans;
    }
};