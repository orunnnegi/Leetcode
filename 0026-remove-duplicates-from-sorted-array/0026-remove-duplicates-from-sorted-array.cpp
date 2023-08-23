#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // auto it= unique(nums.begin(), nums.end());
        // // return nums.begin()-it;
        // // int index= nums.begin()- it;
        // int i= abs(nums.begin()-it);
        // return i;
        set<int> s;
        int n= nums.size();
        for(auto it: nums) s.insert(it);
        int set_size= s.size();
        int i= 0;
        for(auto it: s){
            nums[i++]= it;
        }
        return set_size;
    }
};