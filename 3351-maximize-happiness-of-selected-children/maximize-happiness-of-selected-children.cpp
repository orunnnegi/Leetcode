class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int m=0,add=0;
        long long ans=0;
        int n=happiness.size();
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)break;
                if(happiness[i] - m >0)
                {
                    ans+=happiness[i]-m;
                }
                else {
                    ans+= 0;
                }
                // ans+=add;
                m++;k--;
        }
        return ans;
    }
};