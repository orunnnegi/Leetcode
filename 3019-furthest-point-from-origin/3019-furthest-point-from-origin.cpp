class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r= 0;
        int l= 0;
        int u= 0;
        for(auto it: moves){
            if(it=='L') l++;
            else if(it=='R') r++;
            else u++;
        }
        int ans= max(l, r);
        ans= (u+ans)-(min(l,r));
        return ans;
    }
};