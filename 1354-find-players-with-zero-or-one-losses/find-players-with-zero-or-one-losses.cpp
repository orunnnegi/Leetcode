class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lost;
        map<int, int> wins;
        for(auto it: matches)
        {
            wins[it[0]]++;
            lost[it[1]]++;
        }
        vector<int> temp1, temp2;
        for(auto it: wins)
        {
            if(lost[it.first] == 0)
            {
                temp1.push_back(it.first);
            }
        }
        for(auto it: lost)
        {
            if(it.second == 1)
            {
                temp2.push_back(it.first);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};