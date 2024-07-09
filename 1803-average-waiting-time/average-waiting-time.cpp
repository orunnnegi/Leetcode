class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
      int start = 0;
      double totalWaiting = 0;
     for(int  i =  0 ; i<customers.size();i++){
         while(customers[i][0]>start){
            start++;
         }
      start = start +customers[i][1];
      totalWaiting += start - customers[i][0];

     }
   
    return totalWaiting/customers.size();
    }
};