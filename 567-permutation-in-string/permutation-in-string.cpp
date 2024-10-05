class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //using map+sliding window
        //storing all s1 element in the map
        int n1=s1.size();
        int n2=s2.size();
        unordered_map<char,int>freq;
        for(int i=0;i<n1;i++){
            freq[s1[i]]++;
        }
        //check the length of permutated string from s2
        int cnt=0;
        int i=0,j=0;
        //traversing the whole s2 in one shot using sliding window to check the permutation is present or not
        while(j<n2){
            if(freq.find(s2[j])!=freq.end()){
                freq[s2[j]]--;
                //jokhon map theke frequency komachi jodi frequency 0 hoi element tar thle setake ar map e rekhe lav nei
                //pore oi element take kuje pele tar frequency 0 holeo take dhobe
                if(freq[s2[j]]==0){
                    freq.erase(s2[j]);
                }
                j++;
                cnt++;
            }
            else{
                if(i<j){
                    freq[s2[i]]++;
                    cnt--;
                    i++;
                }
                else{
                    i++;
                    j++;
                }
            }
            if(cnt==n1){
                return true;
            }
        }
        return false;
    }
};