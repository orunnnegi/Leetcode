class DisjointSet {
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++) {
               parent[i] = i;
               size[i] = 1;
            }            
        }

        int findUltimateParent(int node) {
            if(node == parent[node])
               return node;
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u,int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v)
               return;
            if(rank[ulp_u] < rank[ulp_v]) {
               parent[ulp_u] = ulp_v;
            } else if(rank[ulp_u] > rank[ulp_v]) {
               parent[ulp_v] = ulp_u;
            } else {
               parent[ulp_v] = ulp_u;
               rank[ulp_u]++;
            }
        }

        bool unionBySize(int u,int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v)
               return false;
            if(size[ulp_u] < size[ulp_v]) {
               parent[ulp_u] = ulp_v;
               size[ulp_v] += size[ulp_u];
            } else {
               parent[ulp_v] = ulp_u;
               size[ulp_u] += size[ulp_v];
            } 
            return true;
        }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0] > b[0];
        });

        DisjointSet dsAlice(n+1);
        DisjointSet dsBob(n+1);

        int removedEdges = 0, aliceEdges = 0, bobEdges = 0;
        for(auto edge : edges) {
            if(edge[0] == 3) {
                if(dsAlice.unionBySize(edge[1], edge[2])) {
                    dsBob.unionBySize(edge[1],edge[2]);
                    aliceEdges++;
                    bobEdges++;
                } else {
                    removedEdges++;
                }
            } else if(edge[0] == 2) {
                if(dsBob.unionBySize(edge[1], edge[2])) {
                    bobEdges++;
                } else {
                    removedEdges++;
                }
            } else {
                if(dsAlice.unionBySize(edge[1], edge[2])) {
                    aliceEdges++;
                } else {
                    removedEdges++;
                }
            }
        }
        return (bobEdges == n-1 && aliceEdges == n-1) ? removedEdges : -1;
    }
};