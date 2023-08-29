class Solution {
public:
    int bestClosingTime(string customers) {
        int ySuffixSum = 0;
        int nPrefixSum = 0;

        for (int i = 0; i < customers.length(); ++i) 
            if (customers[i] == 'Y') 
                ++ySuffixSum;

        int minPenalty, earliestHour;
        minPenalty = INT_MAX;
        earliestHour = 0;

        for (int i = 0; i <= customers.length(); ++i) {
            int current_penalty = ySuffixSum + nPrefixSum;
            if (current_penalty < minPenalty) {
                minPenalty = current_penalty;
                earliestHour = i;
            }
            if ((i < customers.length() && customers[i] == 'Y') || (i == customers.length()))
                --ySuffixSum;
            else
                ++nPrefixSum;
        }

        return earliestHour;
    }
};