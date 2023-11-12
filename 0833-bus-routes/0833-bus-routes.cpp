class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> routeBusMap; // route id, [bus id0, bus id1, ...]
        for (int i=0; i<routes.size(); ++i) {
            for (auto route: routes[i]) {
                routeBusMap[route].push_back(i);
            }
        }
        
        queue<int> q;
        q.push(source);
        
        int cnt = 0;
        unordered_set<int> visitedRoute, visitedBus;
        visitedRoute.insert(source);
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; ++i) {
                auto startRoute = q.front(); q.pop();
                if (startRoute == target) 
                    return cnt;
                
                for (auto bus: routeBusMap[startRoute]) {
                    if (visitedBus.count(bus)) continue;
                    visitedBus.insert(bus);
                        
                    for (auto nextRoute: routes[bus]) {
                        if (visitedRoute.count(nextRoute)) continue;
                        visitedRoute.insert(nextRoute);
                        q.push(nextRoute);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};