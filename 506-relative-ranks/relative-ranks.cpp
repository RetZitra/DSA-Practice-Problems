class Solution {
public:
//approach:priority queue nie niechi..tate score ar tar respect e index ta store korchi 
//die ekta counter,1 theke barachi priority queue theke element bar korchi..ans er oi index e k er value ta push korchi jodi..k er value (1-3) hoi to gold,silver,bronze hocche
//ar jodi k er value onno hoi to tar respect e k tai push hocche ans vector e
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
          pq.push({score[i],i});
        }
        int k=1;
        vector<string>ans(n,"");
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int index=it.second;
            if(k==1){
                ans[index]="Gold Medal";
            }
            else if(k==2){
                ans[index]="Silver Medal";
            }
            else if(k==3){
                ans[index]="Bronze Medal";
            }
            else{
                ans[index]=to_string(k);
            }
            k++;
        }
        return ans;
    }
};