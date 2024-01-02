class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n= nums.size();
        map<int , int > mpp;
        for(auto it: nums) mpp[it]++;
        vector<vector<int>> v;
        int c= 1;
        while(c<=n){
            vector<int> temp;
            for(auto it: mpp){
                if(it.second){
                    int e= it.first;
                    int f= it.second;
                    temp.push_back(e);
                    mpp[e]= f-1;
                }
            }
            if(temp.size())
            v.push_back(temp);
            ++c;
        }
        return v;
    }
};