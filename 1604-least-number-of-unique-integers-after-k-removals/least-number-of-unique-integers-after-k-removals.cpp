class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map <int,int> mp;
        for(auto i : arr) mp[i]++;
        
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto i : mp)
        {
            pq.push({i.second,i.first});
        }
        
        while(!pq.empty() && k)
        {
            auto it=pq.top();
            pq.pop();
            
            if(it.first>1)
            {
                int v=it.first-1;
                pq.push({v,it.second});
            }
            k--;
        }
        
        return pq.size();
    }
};