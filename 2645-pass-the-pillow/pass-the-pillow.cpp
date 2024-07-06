class Solution {
public:
    int passThePillow(int n, int time) {
       if(time<n){
        return 1+time;
       }
       int initial_pos=1;
       int rotate_time_to_initial_pos=(n-1)*2;
       int extra_rotate;
       if(time>rotate_time_to_initial_pos){
        extra_rotate=time%rotate_time_to_initial_pos;
       }
       else{
        extra_rotate=rotate_time_to_initial_pos%time;
       }
       if(extra_rotate>=n){
        return (1+(rotate_time_to_initial_pos-extra_rotate));
       }
       int current_pos=initial_pos+extra_rotate;
       return current_pos;
    }
};