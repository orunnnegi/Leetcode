class Solution {
public:
    int minimumCost(vector<int>& cost) {
      int ans= 0; int n= cost.size();
      sort(cost.begin(), cost.end(), greater<int>());
      for(int i= 0; i<n; i+=3){
        if(i+1<n){
          ans= ans+(cost[i]+cost[i+1]);
        }
        else{
          ans+= cost[i]; 
        }
      }
      return ans;

    }
};