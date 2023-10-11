class Solution {
public:
    int search(vector<int> &start,int t,int a,int n){
        int x=0;
        while(a<=n){
            int mid=(a+n)/2;
            if(start[mid]<=t){
                a=mid+1;
                x=a;}
            else{
                x=mid;
                n=mid-1;}}
        return x;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> result,start,end;
        for(int i=0;i<flowers.size();i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        for(int i=0;i<people.size();i++){
            int x=search(start,people[i],0,start.size()-1);
            int y=search(end,people[i]-1,0,end.size()-1);
            result.push_back(x-y);
        }
        return result;
    }
};