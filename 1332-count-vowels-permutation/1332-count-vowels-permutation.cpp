class Solution {
public:
    map<char, vector<char>> mp; 
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'}; // O(1) S.C;
    int mod = 1e9+7;
    map<char, int> index;

    int solve(char ch, int n, vector<vector<int>> &dp){
        if(n==0) return 1;
        int res = 0;

        if(dp[index[ch]][n]!=-1) return dp[index[ch]][n];


        for(char c: mp[ch]){
            res += solve(c, n-1, dp);
            res %= mod;
        }
        return dp[index[ch]][n] = res;
    }

    int countVowelPermutation(int n) {
        int ans=0;
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a', 'e', 'o', 'u'};
        mp['o'] = {'u', 'i'};
        mp['u'] = {'a'};

        index['a'] = 0;
        index['e'] = 1;
        index['i'] = 2;
        index['o'] = 3;
        index['u'] = 4;

        vector<vector<int>> dp(5, vector<int> (n+2, -1));

        for(int i=0; i<5; i++){
            ans += solve(vowel[i], n-1, dp);
            ans %= mod;
        }
        return ans;
    }
};