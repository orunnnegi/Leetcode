#include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n= nums.size();
    if(n==1 && k>n) return;
    if(k % n==0) return;
    int t= n-(k%n);
    if(k>n){
        reverse(nums.begin(), nums.begin()+t);
        reverse(nums.begin()+t, nums.end());
        reverse(nums.begin(), nums.end());
    }
    else{
        reverse(nums.begin(), nums.begin()+(n-k));
        reverse(nums.begin()+(n-k), nums.end());
        reverse(nums.begin(), nums.end());


    }

    }
};