class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> newTime;
        // newTime.push_back(intervals[0]);
        int size = intervals.size();
        for(int i = 0; i < size ;i++)
        {
            if(newTime.empty() == true or newTime.back()[1] < intervals[i][0])
            {
                newTime.push_back(intervals[i]);
            }
            else
            {
                newTime.back()[1] = max(newTime.back()[1], intervals[i][1]);
            }
        }
        return newTime;

    }
};