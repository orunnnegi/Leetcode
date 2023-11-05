class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n= arr.size();
        if(k==1) return max(arr[0], arr[1]);
        if(k>=n) *max_element(arr.begin(), arr.end());
        int currwinner= arr[0];
        int conswin= 0;
        for(int i= 1; i<n; i++){
            if(currwinner>arr[i]) conswin++;
            else{
                currwinner= arr[i];
                conswin= 1;
            }
            if(conswin== k) return currwinner;
        }
        return currwinner;
    }
};