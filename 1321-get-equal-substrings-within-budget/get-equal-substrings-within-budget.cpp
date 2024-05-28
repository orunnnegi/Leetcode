class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
    vector<int> a;
    a.push_back(0);
    int p=0;
    for(int i=0;i<s.size();i++){
    p+=abs((int)s[i]-(int)t[i]);
    a.push_back(p);   
    }
    int ans=0;
    for(int i=0;i<a.size();i++){
        int op=upper_bound(a.begin(),a.end(),a[i]+maxCost)-a.begin();
        ans=max(ans,op-i-1);
    }
    return ans;    
    }
};