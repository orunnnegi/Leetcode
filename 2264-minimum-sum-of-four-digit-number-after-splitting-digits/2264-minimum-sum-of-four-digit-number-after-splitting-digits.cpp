class Solution
{
    public:
        int minimumSum(int num) {
            vector<int> digits;
            while(num>0){
                digits.push_back(num%10);
                num/= 10;
            }
            sort(digits.begin(), digits.end());
            return (digits[0]*10+digits[3])+ (digits[1]*10+digits[2]);
        }
};