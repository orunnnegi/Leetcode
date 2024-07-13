#include <bits/stdc++.h>
using namespace std;

#define nline '\n'
#define sp ' '
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

static int fastIO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<tuple<int, int, char, int>> Robots(n);

        for (int i = 0; i < n; i++)
        {
            Robots[i] = make_tuple(positions[i], healths[i], directions[i], i);
        }

        sort(all(Robots));

        stack<tuple<char, int, int>> stk;
        vector<int> result(n, -1);

        for (int i = 0; i < n; i++)
        {
            char direction = get<2>(Robots[i]);
            int health = get<1>(Robots[i]);
            int originalIndex = get<3>(Robots[i]);

            while (!stk.empty() && get<0>(stk.top()) == 'R' && direction == 'L')
            {
                if (get<1>(stk.top()) == health)
                {
                    result[get<2>(stk.top())] = 0;
                    result[originalIndex] = 0;
                    stk.pop();
                    health = 0;
                    break;
                }
                else if (get<1>(stk.top()) > health)
                {
                    get<1>(stk.top()) -= 1;
                    result[originalIndex] = 0;
                    health = 0;
                    break;
                }
                else
                {
                    health -= 1;
                    result[get<2>(stk.top())] = 0;
                    stk.pop();
                }
            }

            if (health > 0)
            {
                stk.push({direction, health, originalIndex});
            }
        }

        while (!stk.empty())
        {
            tuple<char, int, int> top = stk.top();
            stk.pop();
            result[get<2>(top)] = get<1>(top);
        }

        result.erase(remove(result.begin(), result.end(), 0), result.end());

        return result;
    }
};