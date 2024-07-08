class Solution {
//approach:using queue
//queue te first e sob element gulo dhokabo 
//sesh e ektai winner hobe so queue te 1 ta element thakbe
//so queue te jotokhon na ekta element thake
//starting counting initially 0 ,cnt=0
//for each queue front element increase cnt by 1
//if it is kth element means cnt==k then,remove it from the queue that means the kth student from current counting is elemenated,and reset the counting cnt=0,beacause the next element in the queue is traversing from the begining
//if it is not kth element then remove it from queue and push it from the last of the queue because the student currently traversing it's next move is coming at the end because it is a circular queue
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        int cnt=0;
        //pushing n number of student in the queue
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            //counting each front student in the queue (in circular way)
            int student=q.front();
            cnt++;
            q.pop();
            //if it is not kth student in the current counting sequence then remove it from it current position and add it at the end of the queue for next counting sequence
            if(cnt!=k){
                q.push(student);
            }
            //if it is kth element then remove it from the queue beacuse as per rule it must be elemenated and reset the counting sequence means the next student in the queue will be counting from 1 again
            else{
                cnt=0;
            }
        }
        //after the operations the queue contain only one element and that is the winner of the game
        int winner=q.front();
        return winner;
    }
};