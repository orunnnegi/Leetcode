class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        map<char, int> mpp;
        for(auto it: s)  mpp[it]++;
        for(auto it: mpp) pq.push({it.second, it.first});
        string ans= s; int index= 0;
        while(!pq.empty()){
            // pair<int, char> current_popped;
            // auto current_popped= pq.top();
            int curr_freq= pq.top().first;
            while(curr_freq--){
                cout<<index<<" ";
                if(index>=s.length()) index= 1;
                ans[index]= pq.top().second;
                index+=2;
            }
            pq.pop();
        }
        for(int ind= 0; ind<ans.length(); ind++){
            if(ans[ind]==ans[ind+1]) return "";
            else continue;
        }
        return ans;
    }
};