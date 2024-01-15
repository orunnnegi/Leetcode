class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size = nums2.size();
        stack<int> st;
        vector<int> nge(size);
        st.push(nums2[size -1]);
        nge[size - 1]= -1;
        for(int i = size - 2; i >=0 ; i--)
        {
            while(st.empty() == false and st.top() <= nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(nums2[i]);
                nge[i]= -1;
                continue;
            }
            nge[i] = st.top();
            st.push(nums2[i]);
        }
        int n = nums1.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(nums2[j] == nums1[i])
                {
                    ans[i] = nge[j];
                }
            }
        }
        return ans;
    }
};