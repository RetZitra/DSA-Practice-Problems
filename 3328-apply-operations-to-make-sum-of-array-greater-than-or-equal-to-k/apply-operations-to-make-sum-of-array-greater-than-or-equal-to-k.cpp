class Solution {
public:
    int minOperations(int k) {
        int mini=INT_MAX;
        for(int addoneops=0;addoneops<k;addoneops++){
            int newnumber=1+addoneops;
            int dublicateops=(((k+newnumber)-1)/newnumber)-1;
            mini=min(mini,(addoneops+dublicateops));
        }
        return mini;
    }
};