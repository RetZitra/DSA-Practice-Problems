class Solution {
//approach=
//customer sobsomoy cooking start korbe ba current_start_time hobe je first customer ta asche
//tar arrival time die
//die current_start_time ta barte thakbe ei bhabe je current customer er cooking ta sesh korar por je
//current_start_time seta holo (current_start_time+oi perticular customer er cooking er time)==delivered time
//to next customer er jonno etai hobe next current_idle time
//ar each customer er waiting time ki na current customer er (delivered_time(current_start_time+current_duration)-current customer er arrival time)
//to erom kore total customer er waiting time calculate korbo die setake number of customer die devide kore debo bass hoi jabe
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait_time=0;
        double current_start_time=customers[0][0];
        int n=customers.size();
        for(int i=0;i<n;i++){
            int current_arrival_time=customers[i][0];
            int current_duration=customers[i][1];
            //jodi current_start_time current customer er arrival time er cheye choto hoi to chef to order na nie oi time e cook start korte parbe na
            //take oi arrivaltime e order jene oi time e cook start korte hobe to sekhetre idel_time =arrival time hoi jabe
            if(current_start_time<current_arrival_time){
                current_start_time=current_arrival_time;
            }
            double deliverd_time=current_start_time+current_duration;
            wait_time+=(deliverd_time-current_arrival_time);
            cout<<current_start_time<<" "<<deliverd_time<<" "<<wait_time<<endl;
            current_start_time=deliverd_time;
        }
        double ans=(wait_time/n);
        return ans;
    }
};