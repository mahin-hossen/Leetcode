class Solution {
public:
    string reverseWords(string s) 
    {
        string res;
        int start, end;
        for(int i=0;i<s.size();)
        {
            start=i, end=i;
            while(i<s.size() && s[i]!=' ')
            {
                end = i,i++;
            }
            while(end>=start)
            {
                res.push_back(s[end]);
                end--;
            }      
            if(s[i]==' ') res.push_back(' '),i++;
        }
        
        return res;        
    }
};