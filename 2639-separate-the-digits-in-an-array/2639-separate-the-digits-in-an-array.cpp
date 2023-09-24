class Solution {
public:
    void extractDigits(int n, vector<int> &ans){
        vector<int> sux;
        while(n>0){
            sux.push_back(n%10);
            n/=10;
        }
        for(int i= sux.size()-1 ; i>= 0; --i) ans.push_back(sux[i]);
                return;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int it: nums){
            extractDigits(it , ans);
        }
        return ans;
    }
};