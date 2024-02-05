class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        vector<pair<int , int>> temp(size);
        int ind = 0;
        for(auto it: arr)
        {
            temp[ind] = {abs(it - x), it};
            ind++;
        }
        sort(temp.begin(), temp.end());
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(temp[i].second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};