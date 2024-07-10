class Solution {
public:
//approach:
//cnt 0 theke start hocche eta track rakche je main theke kota next folder e jacche mane main folder theke current folder er distance(folder by folder)
//so jodi kono new folder e jai to current position theke 1 barche
//ar jodi back e ase kono folder thle current position theke 1 komche...ar jodi already main folder e thake mane cnt=0 thle ar cnt komanor dokar nei karon main folder er pichone kono folder
//nei
//at least cnt track korche je main folder theke current folder er distance so,otai return korchi karon minimum otoguloi operation korte hobe main folder e firte gele
//jodi ./ hoi to current folder ei stay korche to position er kono changes korar dorkar nei, ei operation ignore korchi
    int minOperations(vector<string>& logs) {
        int cnt=0;
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../" && cnt>0){
                cnt--;
            }
            else if(logs[i]!="../" && logs[i]!="./"){
                cnt++;
            }
        }
        return cnt;
    }
};