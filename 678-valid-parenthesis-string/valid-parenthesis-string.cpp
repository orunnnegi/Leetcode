class Solution {
public:
    bool checkValidString(string s) {
       stack<int>st;
       vector<int>invalid;
       set<int>stars;
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i]==')'){
            if(!st.empty()){
                st.pop();
            }else{
                invalid.push_back(i);
            }
        }
        if(s[i]=='*'){
            stars.insert(i);
        }
       }
       while(!st.empty()){
        invalid.push_back(st.top());
        st.pop();
       }
       sort(invalid.begin(),invalid.end());
       for(auto idx:invalid){
        if(s[idx]=='('){
            auto it=stars.lower_bound(idx);
            if(it!=stars.end()){
                stars.erase(it);
            }else{
                return 0;
            }
        }else if(s[idx]==')'){
            auto it=stars.begin();
            if(it!=stars.end()&&*it<idx){
                stars.erase(it);
            }else{
                return 0;
            }
        }
       }
       return 1;
    }
};