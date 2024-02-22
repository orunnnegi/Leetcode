class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        unordered_map<int,int> mpp;
        int size = trust.size();
        for(int i = 0;i < size;i++){
            mpp[trust[i][1]]++;
            mpp[trust[i][0]]--;
        }

        for(auto it:mpp){
            if(it.second==n-1){
                return it.first;
            }
        }
        return -1;
    }
};