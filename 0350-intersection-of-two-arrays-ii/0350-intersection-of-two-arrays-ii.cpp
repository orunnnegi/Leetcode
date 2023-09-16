class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map1;
        map<int, int> map2;
        for(auto it: nums1) map1[it]++;
        for(auto it: nums2) {map2[it]++;}
        vector<int> ans;
        for(auto it: map2){
            int element= it.first;
            if(map1[element]){
                int totalcount= min(map1[element],map2[element]);
                // totalcount= totalcount/2;
                for(int i=0; i<totalcount; ++i){
                    ans.push_back(element);
                }
            }
        }
        return ans;
    }
};