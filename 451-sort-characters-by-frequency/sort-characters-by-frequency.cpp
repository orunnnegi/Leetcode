class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for(auto it: s)
        {
            freq[it]++;
        }
        priority_queue<pair<int , char>> pq;
        for(auto it: freq)
        {
            pq.push({it.second, it.first});

        }
        int i = 0;
        while(!pq.empty())
        {
            // cout << pq.top().first << pq.top().second << endl;
            int element = pq.top().second;
            int times = pq.top().first;
            for(int j = 0; j < times; j++)
            {
                s[i++] = element;
            }
            pq.pop();
        }
        return s;
        
    }
};