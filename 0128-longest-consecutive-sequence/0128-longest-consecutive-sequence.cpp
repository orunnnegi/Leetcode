class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i= 0; i<nums.size(); i++) s.insert(nums[i]);
        if(s.size()==0) return 0;
        if(s.size()==1 && *s.begin()==0) return 1;
        for(auto it : s) cout<< it << " ";
        int l =1 ; int maxi = 1;
        for(auto it : s){
            if(s.count(it+1)){
                l++;
                maxi= max(l, maxi);
            }
            else{ l= 1;}
        }
        return maxi;
    }
};
