class Solution {
public:
//approcah:basically bottel drink korar por joto gulo bottels drink korchi sob bottel empty hoi jacche
//ar exchange er khetre amra exchange korte parbo jodi jotogulo empty bottels ache seta numExchange er theke equal ba boro hoi ...karon oi numExchage die amra 1 ta full bottel pabo 
//jodi or theke kom empty bottels thake to amra minimum 1 tao full bottel pabo na 
//to full bottel drink korar por segulo empty hole segulo ke jotokhon exchange kora jai kobo,exchange korle full bottels pabo..to full bottels maximize korte hobe
//full bottels pabo(emptybottel/number of bottels needed to exchange 1 full bottel)
//abr ei full bottels guloi drink korar por empty hoi jabe to drink korar por empty bottels+=full bottels
//empty bottels ta track kore rakh bo die dekhbo jotokhon empty bottel die full bottel exchange kora jai..to maximize full bottel
//joto gulo full bottels toto guloi total drink
//tc=O(logn)
    int numWaterBottles(int numBottles, int numExchange) {
        int drink=numBottles;
        int current_empty=numBottles;
        //exchange korte thakbo jotokhon empty ta >=numExchange thakbe
        while(current_empty>=numExchange){
            int current_full=(current_empty/numExchange);
            //remaining empty bottels after exchange and drinking full bottel
            current_empty=(current_empty%numExchange)+current_full;
            drink+=current_full;
        }
        return drink;
    }
};