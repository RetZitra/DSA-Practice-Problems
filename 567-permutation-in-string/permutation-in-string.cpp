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
            // jokhon s2 er oi element ta s1 e poa jacche tokhon ami bolchi je parmuted string er length ta 1 barche
            // ar oi map er oi charecter ta jeheto permuted string e ese jacche tai otar frequency ta komche map theke
            // ar parmuted string er length cnt ta barche
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
            //ar jodi oi last character ta map theke na pai tar mne holo jei substring ta ami check korchi seta break hoi jacche
            //tai ami first theke srink korchi next possible substring kojhar jonno
            //shrink jokhon korbo thokhon jeitar frequency urie diechi seta add korbo karon ota ar mar permuted string e nei
            //ar permuted string er length ta 1 komabo
            else{
                if(i<j){
                    freq[s2[i]]++;
                    cnt--;
                    i++;
                }
                //jodi permuted string er length 0 hoi mne i=j ar current character ta s1 e na thake to i,j 2toi increase korbo next e jabar jonno
                else{
                    i++;
                    j++;
                }
            }
            //jodi valid permuted string er length s1 er same hoi theli oi permuted string ta sw te ache
            if(cnt==n1){
                return true;
            }
        }
        return false;
    }
};