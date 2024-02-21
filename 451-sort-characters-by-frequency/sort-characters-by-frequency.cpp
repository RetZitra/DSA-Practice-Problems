class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(62, 0);
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                int index = s[i] - 'a';
                if (index >= 0 && index <= 26) {
                    index = 10 + (s[i] - 'a');
                    freq[index]++;
                } else {
                    index = 36 + (s[i] - 'A');
                    freq[index]++;
                }
            } else if (isdigit(s[i])) {
                int index = s[i]-'0';
                freq[index]++;
            }
        }
        vector<pair<int,int>>indexed_freq;
        for(int i=0;i<freq.size();i++){
            indexed_freq.push_back({freq[i],i});
        }
        sort(indexed_freq.begin(),indexed_freq.end());
        for(auto it=indexed_freq.rbegin();it!=indexed_freq.rend();it++){
            int diff=it->second;
            int times=it->first;
            if(times==0){
                break;
            }
            if(diff>=0 && diff<=9){
                char ch=diff+'0';
                for(int i=0;i<times;i++){
                    ans+=ch;
                }
            }
            else if(diff>=10 && diff<=35){
                char ch=(diff-10)+'a';;
                for(int i=0;i<times;i++){
                    ans+=ch;
                }
            }
            else{
                char ch=(diff-36)+'A';
                for(int i=0;i<times;i++){
                    ans+=ch;
                }
            }            
        }
        return ans;
    }
};