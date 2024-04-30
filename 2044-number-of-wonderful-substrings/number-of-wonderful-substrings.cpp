class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<long long,int>mp;
        mp[0]=1;
        long long mask=0,ans=0;
        for(auto i: word){
            mask^=(1<<(i-'a'));
            ans+=mp[mask];
            for(long long j=0;j<10;j++) ans+=mp[((1LL<<j)^mask)];
            mp[mask]++;
        }
        return ans;
    }
};