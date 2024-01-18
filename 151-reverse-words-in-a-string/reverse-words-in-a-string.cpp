class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        stack<string> store;
        // string temporary;
        for(int ind = 0; ind < size; ind++)
        {
            string temporary;
            if(s[ind] == ' ')
            {
                continue;
            }
            while(ind < size and s[ind] != ' ')
            {
                temporary+= s[ind];
                ind++;
            }
            store.push(temporary);
        }
        // store.push(temporary);
        string reversed;
        while(store.size() != 1)
        {
            reversed+= store.top()+" ";
            // reversed+= ' ';
            store.pop();
        }
        reversed+= store.top();
        return reversed;

    }
};