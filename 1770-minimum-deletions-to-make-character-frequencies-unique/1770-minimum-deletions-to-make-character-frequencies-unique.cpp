class Solution {
public:
    int minDeletions(string s){

        map<char , int> m;
        for(int i=0 ; i<s.size() ; i++) m[s[i]]++;

        int cnt=0;
        vector<int> v;

        for(auto x:m){
            v.push_back(x.second);
        }

        sort(v.rbegin() , v.rend());
        for(int i=1 ; i<v.size() ; i++){

            if(v[i]==v[i-1] || v[i]>v[i-1]){
                int x=v[i-1]-1;
                if(x<0){
                    cnt+=v[i];
                    v[i]=0;
                }
                else{
                    cnt+=v[i]-x;
                    v[i]=x;
                }
            }
        }    
        return cnt;
    }
};