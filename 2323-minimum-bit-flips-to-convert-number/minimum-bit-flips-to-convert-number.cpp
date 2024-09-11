class Solution {
public:
    //convert the decimal to binary and store into a array
    vector<int>convert(int n){
        vector<int>ans;
        //2 ba onno kichu die kono kichu devide korle atlast seta 1 e ese sesh hoi
        //ar last e thakte pare 1%2 seta 1 ei hoi
        //ba 0%2 seta 0 ei hoi
        while(n>=1){
            ans.push_back(n%2);
            n=n/2;
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        vector<int>t1=convert(start);
        vector<int>t2=convert(goal);
        int n1=t1.size();
        int n2=t2.size();
        int ans=0;
        //jetar binary array er size choto seta ke boro array er size er equal korar jonno
        //jotokhon na boro array er size er hoi totokhon 0 push korte thaklam for easy compare
        if(n1>n2){
            for(int i=n2;i<n1;i++){
                t2.push_back(0);
            }
        }
        else{
            for(int i=n1;i<n2;i++){
                t1.push_back(0);
            }
        }
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                ans++;
            }
        }
        return ans;
    }
};