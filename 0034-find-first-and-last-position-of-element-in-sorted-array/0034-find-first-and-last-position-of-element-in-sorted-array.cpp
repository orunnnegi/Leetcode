class Solution {
public:

    int binarySearch(int low,int high,vector<int> &v,int element) 
    {
        int ans=high+1;;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid]>=element)
                ans=mid,high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& v, int target) {
        if(v.size()==0)
            return {-1,-1};
        int x=binarySearch(0,v.size()-1,v,target);
        if(x==v.size() || v[x]!=target)
            return {-1,-1};
        int y=binarySearch(0,v.size()-1,v,target+1);
        return {x,y-1};
    }
};