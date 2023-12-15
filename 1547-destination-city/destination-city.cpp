class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        vector<string> v;
        int n= paths.size();
        for(int i= 0; i<n; i++){
            v.push_back(paths[i][1]);
        }
        bool flag= true;
        for(int i= 0; i<n; i++){
            flag = true;
            for(int j= 0; j<n; j++){
                if(paths[j][0]== v[i]){ flag =false;break;}
            }
            if(flag) ans= v[i];
        }
        return ans;
    }

};