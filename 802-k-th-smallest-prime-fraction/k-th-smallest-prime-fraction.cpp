class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //minheap priority queue to store {fraction(float),{i,j}}
        priority_queue<pair<float, pair<float, float>>, vector<pair<float, pair<float, float>>>, greater<>> pq;
        // priority_queue<float, vector<float>, greater<>>pq;
        int n=arr.size();
        //check all possible i/j where i<j<n
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                // pq.push({(arr[i]/arr[j]),{arr[i],arr[j]}});
                pq.push({((float)arr[i]/(float)arr[j]),{arr[i],arr[j]}});
            }
        }
        int cnt=1;
        vector<int>ans;
        while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           if(k==cnt){
              int i=(int)it.second.first;
              int j=(int)it.second.second;
              ans.push_back(i);
              ans.push_back(j);
              break;
           }
           cnt++;
        }
        return ans;
    }
};