class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n= pref.size();
        vector<int> v(n);
        // if(n==1) return pref[0];
        v[0]= pref[0];
        for(int i= 1; i<n; i++){
            if(pref[i]==0){
                v[i]= pref[i-1];
            }
            else{
                v[i]= pref[i]^pref[i-1];
            }
        }
        return v;

    }
};