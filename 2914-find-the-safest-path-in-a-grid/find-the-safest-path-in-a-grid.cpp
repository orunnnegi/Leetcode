class Solution {
public:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]) return 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int n1=q.size();
            while(n1--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==0)
                    {
                        grid[nx][ny]=grid[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        vector<vector<int>> visit(n,vector<int>(m,0));
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({grid[0][0],{0,0}});
        visit[0][0]=1;
        while(!pq.empty())
        {
            int safe = pq.top().first;
            int x= pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();
            if(x==n-1&&y==m-1) return safe-1;
            for (int i = 0; i < 4; i++) 
            {
                int nx=x+dx[i]; 
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&visit[nx][ny]==0)
                {
                    grid[nx][ny]=min(safe,grid[nx][ny]);
                    pq.push({grid[nx][ny],{nx,ny}});
                    visit[nx][ny]=1;
                }
            }
        }
        return 0;
    }
};