#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<std::vector<int>>& b, vector<vector<int>>& t) {
        int size = b.size();
        
        ll ans = 0;
        
        
        for (int ind = 0; ind < size - 1; ind++) 
        {
        
        
            for (int j = ind + 1; j < size; j++)
             {

                
                int xmax = min(t[ind][0], t[j][0]);
                
                int ymax = min(t[ind][1], t[j][1]);
                
                
                
                
                int ymin = max(b[ind][1], b[j][1]);
                
                
                int xmin = max(b[ind][0], b[j][0]);
                
                if (ymin < ymax and xmin < xmax) 
                {
                    ll temp = min(xmax - xmin, ymax - ymin);
                    ans = max(ans, 1LL * temp * temp);
                }
            }
        }

        return ans;
 }

};