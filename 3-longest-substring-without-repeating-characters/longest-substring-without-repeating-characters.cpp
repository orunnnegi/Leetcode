class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_map<char , int> checkings;
        int maxLength = 0;
        int left = 0;
        int right = 0;
        while( right < size)
        {
            int element = s[right];
            if(checkings.find(element) != checkings.end())
            {
                
                left = max(checkings[element] + 1, left);


            }
            checkings[element] = right;
            
            
            maxLength = max(maxLength , right - left + 1);
            right++;
            
        }
        return maxLength;
    }
};