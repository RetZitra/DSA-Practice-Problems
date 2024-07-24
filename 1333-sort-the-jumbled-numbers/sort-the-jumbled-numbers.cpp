class Solution {
public:
    string getmapvalue(string s,vector<int>& mapping){
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            int digit=s[i]-'0';
            int mapped_digit=mapping[digit];
            temp+=to_string(mapped_digit);
        }
        return temp;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        //store the mapped value of the original value given in the array and store it's index in the vector of pair for access the real number
        vector<pair<int,int>>mapped_value_with_index;
        //generate all mapped the values in the from of string so that there is no datatype runtime error,ingnoring multiply with 10
        for(int i=0;i<n;i++){
           string temp=to_string(nums[i]);
           string map_value=getmapvalue(temp,mapping);
           long long mapped_digit=stol(map_value);
           mapped_value_with_index.push_back({mapped_digit,i});
        }
        //sort the mapped value in asending order,if two number is same then it will sort according 
        //to it's index number which is store in the pair..which satisfy the question condition that 
        //if two number is same it will be sorted according to it's index..which number came first it 
        //will come first
        sort(mapped_value_with_index.begin(),mapped_value_with_index.end());
        for(int i=0;i<n;i++){
            int index=mapped_value_with_index[i].second;
            ans[i]=nums[index];
        }
        return ans;
    }
};