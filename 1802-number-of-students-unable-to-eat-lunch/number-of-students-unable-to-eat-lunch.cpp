class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int>freq;
        for(int i=0;i<students.size();i++){
            freq[students[i]]++;
        }
        int i=0;
        while(i<sandwiches.size()){
            if(freq[sandwiches[i]]>0){
                freq[sandwiches[i]]--;
                i++;
            }
            else{
                if(sandwiches[i]==0){
                    return freq[1];
                }
                else{
                    return freq[0];
                }
            }
        }
        return 0;
    }
};