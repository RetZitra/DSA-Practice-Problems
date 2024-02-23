class Solution {
public:
    int addDigits(int num) {
        if(num/10<=0){
            return num;
        }
        else{
            int sum=0;
            int finalsum=0;
            while(num>0){
                sum+=num%10;
                num/=10;
                if(num<=0){
                    num=sum;
                    finalsum=sum;
                    sum=0;
                    if(finalsum/10<=0){
                        return finalsum;
                    }
                }
            }
            return 0;
        }
    }
};