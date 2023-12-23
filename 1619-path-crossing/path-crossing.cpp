class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        pair<int,int> point(0,0);
        visited.insert(point);
        for(const auto& d : path){
            if(d == 'N')
                point.second = point.second + 1;
            else if(d == 'S')
                point.second = point.second - 1;
            else if(d == 'E')
                point.first = point.first + 1;
            else if(d == 'W')
                point.first = point.first - 1;
            if(visited.find(point) != visited.end())
                return true;
            visited.insert(point);     
        }
        return false;
    }
};