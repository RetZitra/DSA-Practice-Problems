class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        if(n==1){
            return n;
        }
        stack<int>st1;
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            st1.push(s[i]);
        }
        char prev=s[0];
        int cnt=0;
        while(!st1.empty()){
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