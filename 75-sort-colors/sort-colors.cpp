class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n= nums.size();
        // for(int i= 0; i<n-1; i++){
        //     for(int j= 0; j<n-i-1; j++){
        //         if(nums[j]>nums[j+1]){
        //             swap(nums[j+1], nums[j]);
        //         }
        //     }
        // }
        // return;
        
    //     int n= nums.size();
    //     int a= 0;
    //     int b= 0;
    //     int c= 0;
    //     for(int i = 0; i<n; i++){
    //         if(nums[i] == 0){
    //             ++a;
    //         }
    //         else if(nums[i] == 1){
    //             ++b;
    //         }
    //         else{
    //             ++c;    tc= O(N) + O(N) -> O(N) sc= O(1)
    //         }
    //     }
    //     for(int i= 0; i<n; i++){
    //         if(i<a){
    //             nums[i] = 0;
    //             continue;
    //         }
    //         else if(i >= a and i< (a+b)){
    //             nums[i] = 1;
    //         }
    //         else{
    //             nums[i] = 2;
    //         }
    //     }
    //     return ;

    // }

        int n= nums.size();
        int low= 0;
        int mid= 0;
        int high= n-1;
        while(mid<= high)
        {
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                    low++;
                    ++mid;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                    high--;
            }
        }

        return;

    }
};