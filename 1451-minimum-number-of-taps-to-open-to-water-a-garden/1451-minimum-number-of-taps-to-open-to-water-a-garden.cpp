class Solution {
public:
    void deleteOperations(unordered_map<int,int>&mp,int &temp,int &dist){
        vector<int> toErase;

        for(pair<int,int> p : mp){
            int idx = p.first;
            int range = p.second;

            if(idx - range <= dist){
                temp = max(temp,idx + range);
                toErase.push_back(idx);
            }
        }

        for(int i=0;i<toErase.size();i++){
            mp.erase(toErase[i]);
        }
    }
    int minTaps(int n, vector<int>& ranges) {
       unordered_map<int,int> mp;

       for(int i=0;i<=n;i++){
           if(ranges[i] > 0)
            mp[i] = ranges[i];
       }

       int dist = 0,temp = 0;
       deleteOperations(mp,temp,dist);

       dist = temp;
       int cnt = 1;
       
       while(true){
            if(dist >= n) return cnt;

            cnt++;
            deleteOperations(mp,temp,dist);

            if(temp <= dist) return -1;
            dist = temp;
       }

       return -1;
    }
};