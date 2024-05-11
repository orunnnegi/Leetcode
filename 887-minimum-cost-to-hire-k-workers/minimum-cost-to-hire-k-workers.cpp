class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        std::vector<std::pair<double, int>> ratioQuality;
        for (int i = 0; i < n; ++i) {
            ratioQuality.push_back({(double)wage[i] / quality[i], i});
        }
        std::sort(ratioQuality.begin(), ratioQuality.end());
        std::priority_queue<int> maxHeap;
        double minCost = std::numeric_limits<double>::max();
        double qualitySum = 0;
        for (auto [ratio, index] : ratioQuality) {
            qualitySum += quality[index];
            maxHeap.push(quality[index]);

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                minCost = std::min(minCost, ratio * qualitySum);
            }
        }
        return minCost;
    }
};