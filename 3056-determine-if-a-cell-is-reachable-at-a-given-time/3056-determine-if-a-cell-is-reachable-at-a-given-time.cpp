class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy - fy);

        if (!x and !y) {
            return t != 1;
        }

        return x <= t and y <= t;
    }
};