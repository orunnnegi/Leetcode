
class Disjoint{
    vector<int> parent;
    public:

    Disjoint(int size){
        parent.resize(size);
        for(int i=0;i<size;i++){
            parent[i]=i;
        }
    }

    int findparent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findparent(parent[x]);
    }

    bool Union(int a,int b){
        a=findparent(a);
        b=findparent(b);

        if(a==b){
            return false;
        }
        parent[b]=a;
        return true;
    }

};


class Solution {

static bool cmp(vector<int>&a , vector<int>&b){
      return a[2]<b[2];
  }

public:
  
  int findmst(vector<vector<int>>&edges,int n,int include,int exclude){
      int weight=0;
      Disjoint d(n);
      if(include!=-1){
          weight+=edges[include][2];
          d.Union(edges[include][0],edges[include][1]);
          exclude=include;
      }
      for(int i=0;i<edges.size();i++){
          if(i==exclude)continue;

          if(d.Union(edges[i][0],edges[i][1])){
              weight+=edges[i][2];
          }

      }

      for(int i=0;i<n;i++){
          if(d.findparent(i)!=d.findparent(0)){
              return INT_MAX;
          }
      }
    
    return weight;

  }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
           for(int i=0;i<edges.size();i++){
               edges[i].push_back(i);
           }
           sort(edges.begin(),edges.end(),cmp);

           vector<vector<int>>ans(2);

           int originalmst= findmst(edges,n,-1,-1);
          
          for(int i=0;i<edges.size();i++){
               
               int exclude= findmst(edges,n,-1,i);
               
               if(exclude>originalmst){
                   ans[0].push_back(edges[i][3]);
               }
               else{
                int include= findmst(edges,n,i,-1);
                 if(include==originalmst){
                     ans[1].push_back(edges[i][3]);
                 }
               }
          }
         
         return ans;
           
    }
};