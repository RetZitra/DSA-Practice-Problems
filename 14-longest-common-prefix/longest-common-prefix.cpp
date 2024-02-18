class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (const string str : strs) {
            for (char ch : str) {
                ans.push_back(ch);
            }
            break;
        }
        for (const string str : strs) {
            int i=0;
            for (char ch : str) {
                //jodi jei string take amra ans hosabe dhore nicchi star first character kono ekta string er first character er sathe match na kore thle kono common prefix nei
                if(i==0){
                    if(ch!=ans[i]){
                        ans.erase();
                        return ans;
                    }
                }
                if(i<ans.size()){
                    if(ch==ans[i]){
                        i++;
                    }
                    else{
                        break;
                    }
                }
            }
            //jodi ans ta kohono faka hoi jai mane common prefix nei tai return kore dicchi
            //faltu iteration na kore
            if(ans.size()==0){
                return ans;
            }
            if(i<ans.size()){
               ans.erase(i,(ans.size()-i));
            }
        }
        return ans;
    }
};