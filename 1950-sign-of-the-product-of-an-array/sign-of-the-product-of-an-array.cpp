class Solution {
public:
    int arraySign(vector<int>& array) {
        int n= array.size();
        int signTillNow = 1;
	for(int index = 0; index < n ; index++)
	{
		if(array[index] > 0)
		{
			signTillNow*= 1;
		}
		else if(array[index] < 0)
		{
			signTillNow*= -1;
		}
		else
		{
			signTillNow = 0;
            return 0;
		}
		
	}
    return signTillNow;
    }
};