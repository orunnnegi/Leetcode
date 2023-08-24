class Solution {
public:

    string appendSpace(string s,int space)
    {
       for(int i=0; i<space; ++i)
       {
           s+=" ";
       }
       return s;
    }
   
    string addSpace(vector<string> temp,int maxWidth,int len)
    {
          int vlen = temp.size();
          int slen = maxWidth-len;
          int gap = vlen-1;
          if(gap==0) return appendSpace(temp[0],slen);
          string s="";
          vector<string> v(gap,"");
           
           while(slen>0)
           {
               for(int i=0; i<v.size(); ++i)
               {
                   if(slen>0) v[i]+=" ";
                   else break;
                   slen--;
               }
           }
           
           int i=0;
           for(i=0; i<v.size(); ++i)
           {
              s+=temp[i]+v[i];
           }
           s+=temp[i];
           
           return s;
        }
     
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> temp,ans;
        int len =0,i=0;

        while(i<words.size())
        {
            if(len+words[i].size()<=maxWidth)
            {
                len+=words[i].size()+1;
                if(i+1>=words.size()) temp.push_back(words[i]);
                else temp.push_back(words[i]+" ");
                i++;
            }
            else
            {
                string s2 = temp[temp.size()-1];
                string subString = s2.substr(0,s2.size()-1);
                temp[temp.size()-1]=subString;
                string s = addSpace(temp,maxWidth,len-1);
                ans.push_back(s);
                len=0;
                temp.clear();
            }
        }
        
        string s1="";
        for(int j=0; j<temp.size(); j++)
        { 
            s1=s1+temp[j];
        }
        
        s1 = appendSpace(s1,maxWidth-s1.size());
        ans.push_back(s1);
        return ans;
    }
};