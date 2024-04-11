class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        queue<int>q;
        vector<int>ans(n);
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
           q.push(i);
        }
        int j=0;
        while(!q.empty()){
            int index1=q.front();
            q.pop();
            if(!q.empty()){
                int index2=q.front();
                q.pop();
                q.push(index2);
            }
            ans[index1]=deck[j];
            j++;
        }
        return ans;
    }
};