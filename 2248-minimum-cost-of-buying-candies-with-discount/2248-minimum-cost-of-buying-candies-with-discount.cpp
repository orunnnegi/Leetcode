class Solution {
public:
    int minimumCost(vector<int>& cost) {
      int ans= 0; int n= cost.size();
      // sort(cost.begin(), cost.end(), greater<int>());
      // for(int i= 0; i<n; i+=3){
      //   if(i+1<n){
      //     ans= ans+(cost[i]+cost[i+1]);
      //   }
      //   else{
      //     ans+= cost[i]; 
      //   }
      // }
      // return ans;
      sort(cost.begin(), cost.end());
      for(int i= n-1; i>=0;i-=3){
          if(i-1<0){
            ans+= cost[i];
          }
          else{
            ans= ans+cost[i]+cost[i-1];
          }
      }
      return ans;


    }
};