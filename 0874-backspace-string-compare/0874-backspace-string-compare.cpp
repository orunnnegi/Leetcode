class Solution {
    string getFinalString(string str)
    {
        string newString = "";
        for(auto ch : str)
        {
          if(ch != '#') 
             newString += ch; 
           else if(newString.size()) 
             newString.pop_back();
        }
    return newString;
    }
public:
    bool backspaceCompare(string s, string t) {
     return getFinalString(s) == getFinalString(t);
    }
};