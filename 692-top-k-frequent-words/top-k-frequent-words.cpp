class Solution {
public:

    static bool comparator(pair<string, int> &a, pair<string, int> &b)
    {
        return a.second > b.second || (a.second == b.second and a.first < b.first) ;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mpp;
        vector<pair<string, int>> temp;
        for(string it: words)
        {
            mpp[it]++;
        }
        for(auto it: mpp)
        {
            temp.push_back({it.first, it.second});
        }
        sort(temp.begin(), temp.end(), comparator);
        vector<string> ans;
        int i = 0;
        while(i < k)
        {
            ans.push_back(temp[i].first);
            i++;
        }
        return ans;
        
    }
};