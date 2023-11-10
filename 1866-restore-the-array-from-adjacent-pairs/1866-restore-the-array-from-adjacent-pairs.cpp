class Solution {
private:
    static constexpr int MINV = -100000, MAXV = 100000;
    static constexpr unsigned RANGEV = MAXV - MINV + 1u;
    typedef unsigned long long u64;
    static u64 index[RANGEV];

    static unsigned lo(const u64 p) __attribute__((always_inline)) {
        return p & UINT_MAX;
    }

    static unsigned hi(const u64 p) __attribute__((always_inline)) {
        return p >> 32;
    }

    static void addp(u64 &p, const unsigned i) __attribute__((always_inline)) {
        p += (u64)i << ((p != 0) << 5);
    }

    static void removep(u64 &p, const unsigned i) __attribute__((always_inline)) {
        if (lo(p) == i) p = hi(p);
        else if (hi(p) == i) p = lo(p);
    }

public:
    vector<int> restoreArray(const vector<vector<int>>& apairs) {
        const unsigned n = apairs.size();
        if (n == 1) return apairs.front();
        int minv = MAXV, maxv = MINV;
        for (unsigned i = 0; i < n; i++) {
            const auto &ap = apairs[i];
            const int v0 = ap[0], v1 = ap[1];
            addp(index[v0-MINV], i + 1);
            addp(index[v1-MINV], i + 1);
            const auto [mn, mx] = minmax(v0, v1);
            minv = min(mn, minv);
            maxv = max(mx, maxv);
        }

        int head = minv;
        while (head <= maxv && index[head-MINV] - 1u >= UINT_MAX)
            head++;

        vector<int> r;
        r.reserve(n + 1);
        r.push_back(head);
        for (u64 idx = index[head-MINV]; idx; idx = index[head-MINV]) {
            const auto &ap = apairs[lo(idx) - 1];
            index[head-MINV] >>= 32;
            r.push_back(head = ap[ap[0] == head]);
            removep(index[head-MINV], lo(idx));
        }
        fill(index - MINV + minv, index - MINV + maxv + 1, 0u);
        return r;
    }
};

Solution::u64 Solution::index[RANGEV];