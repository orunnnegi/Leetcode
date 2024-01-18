class Solution {
public:

    void helper(int index, string digits, unordered_map<int , string> &phone, int size, string temp, vector<string> &ans)
    {
        if(index == size)
        {
            ans.push_back(temp);
            return;
        }
        int curr = digits[index];
        string currLetters = phone[curr];
        for(int j = 0; j < currLetters.size(); j++)
        {
            temp+= currLetters[j];
            helper(index + 1, digits, phone, size, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int size = digits.size();
        if(size == 0)
        {
            return ans;
        }
        unordered_map<int, string> phone;
        phone['2']="abc";
        phone['3']="def";
        phone['4']="ghi";
        phone['5']="jkl";
        phone['6']="mno";
        phone['7']="pqrs";
        phone['8']="tuv";
        phone['9']="wxyz";
        helper(0, digits, phone, size, "", ans);
        return ans;

    }
};