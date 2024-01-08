class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size(); // calc the size 
        unordered_map< int , int > occurences; 
        int targetCondition = size/3;
        vector< int > allMajorityElements; 
        for(int index = 0; index < size; index++)
        {
            occurences[nums[index]]++;
        }
        for(auto &[a, b] : occurences)
        {
            if(b > targetCondition)
            {
                allMajorityElements.push_back(a);
            }
        }

        return allMajorityElements;
    }
};