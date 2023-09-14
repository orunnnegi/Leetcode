class Solution {

    unordered_map<string, vector<string>> graph;
    vector<string> path;
    
    bool DFS(string src, int edgesLeft)
    {
        if(edgesLeft == 0)
            return true;

        auto neighboursIter = graph.find(src);
        if(neighboursIter == graph.end())
            return false;
        for (auto iter = neighboursIter->second.begin(); iter != neighboursIter->second.end(); iter++)
        {
            string dest = *iter;
            if(dest.empty())
                continue;

            path.push_back(dest);
            *iter = "";

            if (DFS(dest, edgesLeft - 1))
                return true;
            
            *iter = dest;
            path.pop_back();
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    
        for(auto edge : tickets)
            graph[edge[0]].push_back(edge[1]);
        
        for(auto &[src, neighbours] : graph)
            sort(neighbours.begin(), neighbours.end());

        path.push_back("JFK");
        DFS("JFK", tickets.size());

        return path;
    }
};