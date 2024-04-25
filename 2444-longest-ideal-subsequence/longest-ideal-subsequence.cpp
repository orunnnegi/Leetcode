class Solution {
public:
    int longestIdealString(string s, int k) {
        /*
        apne as pas walo me jis jis se connect ho skte ho unme se jisme max h use 
        connect ho jao
        */
        int arr[26]={0},result=0;
        int a=0,b=25;
        for(int i=0;i<s.length();i++){
            a=0,b=25;
            int l=s[i]-'a';
            a=max(a,l-k);
            b=min(b,l+k);
            int max=0;
            //cout<<a<<" "<<b<<" "<<l<<" ";
            while(a<=b){
               if(arr[a]>max) max=arr[a];
                a++;
            }
           // cout<<max<<endl;
            arr[l]=max+1;
            if(arr[l]>result) result=arr[l];
        }
        return result;
    }
};