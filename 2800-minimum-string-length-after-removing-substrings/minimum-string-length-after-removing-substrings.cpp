class Solution {
public:
//approach:amk 2to kore character check korte hobe ar jodi in-between kichu character delete hoi thle oi delete hobar
// ager character gulo dhore rekhte hobe tai ekta datastructure chai jake stack bolbo karon tate last jeta dhokabo
// seta first berobe to ekhetre seta oi in-between delected character gulor ager character hobe top to bottom

//so jodi stack e kichu thake thle oi stack er top ta holo current jeta amr character ache tar previous character
//ebar jodi oi je 2to ke compare korchi segulo delete na hoi to current element takeo stack e purbo(first e agar stack e jeta chilo seta purbo trpr,current jeta seta) 
// seta next iteration er jonno previous element hobe ar str[i+1] ta next character hobe to compare

//ar jodi delete hoi to stack theke oi previous element take delete kore debo , tokhon next character hobe str[i+1] and previous character hobe stack theke jeta deleted holo tar ager character ta
//ebhabe kota kore character deleted hocche seta count korte thakbo,die sesh e main jota string e character chilo seta theke deleted number of character bad dieli current kota character 
// pore ache peye jabo
    int minLength(string s) {
        int n=s.size();
        //edge case jodi 1 tai character thake to 2to character compare korte parbo na sekhetre 0 return hobe
        if(n==1){
            return n;
        }
        stack<int>st1;
        int cnt=0;
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            st1.push(s[i]);
        }
        char prev=s[0];
        while(!st1.empty()){
            //edge case
            //mne delete korar por ektai character pore ache ar compare korar jonno 2to character nei tai 1 return hobe
            if(st1.size()==1 && st2.size()==0){
                return 1;
            }
            char prev;
            if(!st2.empty()){
                prev=st2.top();
                st2.pop();
            }
            else{
                prev=st1.top();
                st1.pop();
            }
            char curr=st1.top();
            st1.pop();
            if((prev=='A' && curr=='B')|| (prev=='C' && curr=='D')){
                cnt+=2;
            }
            else{
                //st2 te jate last er character ta first e ase tai age first er ta dokhabo trpr last er ta dhokabo
                st2.push(prev);
                st2.push(curr);
            }
        }
        int ans=n-cnt;
        return ans;
    }
};