class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans= 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n= g.size();
        for(int i= 0; i<n; i++){
            int ind = lower_bound(s.begin(), s.end(), g[i])- s.begin();
            if(ind<s.size()){
            ans++;
            s.erase(s.begin()+ind);
            }

        }
        return ans;
    }
};