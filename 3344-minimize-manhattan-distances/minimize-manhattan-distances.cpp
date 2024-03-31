class Solution {
public:
   
    int minimumDistance(vector<vector<int>>& a) {
       vector<pair<int,int>> v;
        // what if we remove this point ?
        multiset<int> sum;
        multiset<int> diff;
        for(auto it:a){
            sum.insert(it[0]+it[1]);
            diff.insert(it[0]-it[1]);
        }
        int ans=INT_MAX;
        int n=a.size();
        for(int i=0;i<n;i++){
            int cursum=a[i][0]+a[i][1];
            int curdiff=a[i][0]-a[i][1];
            sum.erase(sum.find(cursum));
            diff.erase(diff.find(curdiff));
            // //min of diff, sum waali values 
            int curans=INT_MAX;
            int val1=*(sum.rbegin())- *(sum.begin());
            int val2=*(diff.rbegin())- *(diff.begin());
            curans=max(val1,val2);
            ans=min(ans,curans);
            sum.insert(cursum);
            diff.insert(curdiff);
        }
        
        return ans;
    }
};