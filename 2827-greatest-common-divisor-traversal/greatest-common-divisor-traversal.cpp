
//class for union find
class DS
{
    public:
  vector<int> parent, size;

  DS(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = find(parent[node]);
  }

  void union_size(int u, int v)
  {
    int ulp_u = find(u);
    int ulp_v = find(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }

        //adding each value to sets of its factors
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==1){
                return false;
            }
            for(int j=2 ; j*j<=nums[i] ; j++){
                if(nums[i]%j==0){
                    mp[j].push_back(i);
                    int k=nums[i]/j;
                    if(k==j){
                        continue;
                    }
                    mp[k].push_back(i);
                }
            }
            mp[nums[i]].push_back(i);
        }
        
        //combining/ union of values having same factor
        DS ds(nums.size());
        for(auto m : mp ){
            int x=m.first;;
            for(int i=0 ; i<mp[x].size()-1 ; i++){
                ds.union_size(ds.find(mp[x][i]),ds.find(mp[x][i+1]));
            }
        }
        int count=0;
        for(int i=0 ; i<nums.size() ; i++){
            if((ds.find(i)==i)){
                count++;
            }
            if(count>1){
              return false;
            }
        }

        //if all belong to same group
        if(count==1){
            return true;
        }

        return false;
    }
};