class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
        int c= 0;
        set<int> s1;
        for(int i= 1; i<=k; i++) s1.insert(i);
        set<int> s2;
        for(int i= 0; i<n; i++){
            s2.insert(nums[n-i-1]);
            c++;
            int j= 0;
            int m= 0;
            for(auto it: s2){
                int nanga= it;
                int changa= *next(s1.begin(), j);
                if(nanga!=changa) continue;
                else m++;
                ++j;
            }
            if(m==k) break;
        }
        return c;
        
    }
};