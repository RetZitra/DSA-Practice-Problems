class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        long long ans=0;
        for(int i=0;i<n;i++){
            int index=word[i]-'a';
            freq[index]++;
        }
        sort(freq.begin(),freq.end(),[](int a,int b){
            return a>b;
        });
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                return ans;
            }
            else{
                //0 based indexing so counting is 1 less
                //1-8
                if(i>=0 && i<=7){
                  ans+=freq[i]*1;
                }
                //9-16
                else if(i>7 && i<=15){
                    ans+=freq[i]*2;
                }
                //17-24
                else if(i>15 && i<=23){
                    ans+=freq[i]*3;
                }
                //25-26
                else{
                    ans+=freq[i]*4;
                }
                }
        }
        return ans;
    }
};