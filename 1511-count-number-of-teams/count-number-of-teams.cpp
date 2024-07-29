class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count=0;
        int n=rating .size();
        for(int i=0;i<n;i++){
            int left_greater=0,left_smaller=0,right_greater=0,right_smaller=0;

            for(int j=i-1;j>=0;j--){
                if(rating[j] < rating [i]){
                    left_smaller++;
                }else{
                    left_greater++;
                }
            }

            for(int j=i+1;j<n;j++){
                if(rating[j] < rating [i]){
                    right_smaller++;
                }else{
                    right_greater++;
                }
            }

            count+=(right_smaller*left_greater)+(right_greater*left_smaller);
        }

        return count;
    }
};