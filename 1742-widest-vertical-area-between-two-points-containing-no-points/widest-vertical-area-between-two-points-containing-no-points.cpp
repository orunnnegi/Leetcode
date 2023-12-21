class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int>&p2)->bool{
            return p1[0] < p2[0];
        });
        int maxWidth = 0, sz = points.size();
        for(int indx = 0; indx < sz-1; indx++){
           vector<int> & point1 = points[indx], &point2 = points[indx+1]; 
           maxWidth = max(maxWidth, point2[0] - point1[0]);
        }
        return maxWidth;
    }
};