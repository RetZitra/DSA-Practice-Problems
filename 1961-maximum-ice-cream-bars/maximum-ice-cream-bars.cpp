class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxicecream=0;
        sort(costs.begin(),costs.end());
        int n=costs.size();
        for(int i=0;i<n;i++){
           if(coins>=costs[i]){
               maxicecream++;
               coins=coins-costs[i];
           }
           else{
               break;
           }
        }
        return maxicecream;
    }
};