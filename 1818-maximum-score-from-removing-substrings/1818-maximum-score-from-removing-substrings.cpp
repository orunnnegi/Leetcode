class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(y>x){
            for(auto &c:s){
                if(c=='a') c = 'b';
                else if(c=='b') c = 'a';
            }
            swap(y,x);
        }
        string temp = "";
        for(auto c:s){
            if(c=='b' && !temp.empty() && temp.back()=='a'){
                ans+=x;
                temp.pop_back();
            } else temp+=c;
        }
        s = temp;
        temp = "";
        for(auto c:s){
            if(c=='a' && !temp.empty() && temp.back()=='b'){
                ans+=y;
                temp.pop_back();
            } else temp+=c;
        }
        return ans;
    }
};