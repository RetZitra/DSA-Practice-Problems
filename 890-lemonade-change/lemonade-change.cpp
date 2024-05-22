class Solution {
public:
//approach:3 te coin ache 5 er 10 er ar 20 er..each price holo 5
//amk dekte hobe je ami change dite parbo kina..mne 10 taka keu dile amk 1 ta 5 er coin change dite hobe..ar amr hate asbe 10 er coin
//jodi keu 20 taka dei thke amk (1 ta 10 er coin + 1 ta 5 er coin dite hobe)= mot 15 er coin dite hobe..ar amr hate asbe 20 er coin
//ekhane 20 er coin kota hate elo seta calculate korar dorkar ei nei karon..amk jodi 10 bill er jonno 5 er coin return korte hocche..ar 20 er bill er jonno
//10 ar 5 er coin change korte hocche...tai change dite parbo kina seta dekhar jonno 5 ar 10 er coin kota hate elo seta calculate korlei hobe
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five_coin=0;
        int ten_coin=0;
        // int twenty_coin=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five_coin++;
            }
            else if(bills[i]==10){
                //if bill is 10 then we have to return 1 5's coin..so check if i have minimum 1 5's coin to change
                if(five_coin>=1){
                    five_coin--;
                    //we recieve 1 ten_coin in these transaction
                    ten_coin++;
                }
                // if i don't have sufficient 5's coin then i can't take the payment
                else{
                    return false;
                }
            }
            else{
                //if bill is 10 then we have to return 1 5's coin and 1 10's coin..so check if i have minimum 1, 5's and 10's coin to change
                if(five_coin>=1 && ten_coin>=1){
                    five_coin--;
                    ten_coin--;
                     //we recieve 1 tweney_coin in these transaction
                    // twenty_coin++;
                }
                //3te te 5 er coin dieo 15 taka return kora jai
                else if(five_coin>=3){
                    five_coin-=3;
                }
                // if i don't have sufficient 5's and 10's coin then i can't take the payment
                else{
                    return false;
                }
            }
        }
        //if we succesfully change all transaction means we dont get any false condition while traversing the array we simply say that we can change all bills
        return true;
    }
};