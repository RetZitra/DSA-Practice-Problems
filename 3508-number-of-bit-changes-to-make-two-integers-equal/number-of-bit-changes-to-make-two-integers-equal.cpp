class Solution {
public:
//function of binary to decimal but in reverse order
    vector<int>dec_to_bin(int k){
        vector<int>a;
        while(k>1){
            a.push_back(k%2);
            k=k/2;
        }
        a.push_back(1);
        return a;
    } 
    int minChanges(int n, int k) {
        long long count=0;
        if(n==k){
            return 0;
        }
        vector<int>a=dec_to_bin(n);
        vector<int>b=dec_to_bin(k);
        int n1=a.size();
        int n2=b.size();
        int i=0;
        for(i=0;i<n1 && i<n2;i++){
            if(a[i]==1 && b[i]==0){
                count++;
            }
            else if(a[i]==0 && b[i]==1){
                return -1;
            }
        }
        if(i<n1){
            while(i<n1){
                if(a[i]==1){
                    count++;
                }
                i++;
            }
        }
        else if(i<n2){
            return -1;
        }
        return count;
    }
};