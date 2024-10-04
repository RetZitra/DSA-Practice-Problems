class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        //set e winners ra thakbe
        set<int>winners;
        //lost_frequency stored the number of loose of each player
        //jara harche tara koto bar harche tader frequency
        map<int,int>lost_freq;
        for(int i=0;i<n;i++){
            winners.insert(matches[i][0]);
            lost_freq[matches[i][1]]++;
        }
        vector<vector<int>>ans;
        vector<int>t0;
        vector<int>t1;
        for(auto it:winners){
            //jesob winners ra lost frequency te nei tara ekbar o hareni
            if(lost_freq.find(it)==lost_freq.end()){
                t0.push_back(it);
            }
        }
        for(auto it:lost_freq){
            //jara harche tara map e thakbe thle dekhbo je jara harche tara ki ekbar ei harche
            //thle map e tader frequency 1 hobe
            if(it.second==1){
                t1.push_back(it.first);
            }
        }
        //before return sort them both
        sort(t0.begin(),t0.end());
        sort(t1.begin(),t1.end());
        ans.push_back(t0);
        ans.push_back(t1);
        return ans;
    }
};