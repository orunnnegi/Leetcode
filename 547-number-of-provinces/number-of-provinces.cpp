class Solution {

private:
    void dfs(int node , vector<int> &vis, vector<vector<int>> &list)
    {
        vis[node] = 1;
        for(auto neighbours : list[node])
        {
            if(vis[neighbours] == 0)
            {
                dfs(neighbours, vis, list);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalNodes = isConnected.size();
        vector<vector<int>> list(totalNodes);
        for(int i = 0; i < totalNodes ; i++)
        {
            for(int j = 0; j < totalNodes; j++)
            {
                if(isConnected[i][j] == 1 and i != j)
                {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        int provinces = 0;
        vector<int> vis(totalNodes+1 , 0);
        for(int currNode = 0; currNode < totalNodes ; currNode++)
        {
            if(vis[currNode] == 0)
            {
                dfs(currNode, vis, list);
                provinces ++;
            }

        }
        return provinces;
    }
};