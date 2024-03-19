class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        int size = v.size();
        vector<int> ans;
        for(int ind = 0; ind < size; ind++)
        {
            int index = abs(v[ind]) - 1;
            v[index] *= -1;
            if(v[index] >= 1)
            {
                ans.push_back(abs(v[ind]));
            }
        }
        return ans;
    }
};