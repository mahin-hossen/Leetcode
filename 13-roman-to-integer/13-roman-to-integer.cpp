class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int> value = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int amount = 0;
        char lastChar = 'A';
        
        for(int i=s.size();i>=0;i--)
        {  
            if(s[i]=='I' && (lastChar =='V' || lastChar=='X'))
                amount-=value[s[i]];
            else if(s[i]=='X' && (lastChar =='L' || lastChar=='C'))
                amount-=value[s[i]];
            else if(s[i]=='C' && (lastChar =='D' || lastChar=='M'))
                amount-=value[s[i]];
            else  amount+= value[s[i]];
            lastChar = s[i];
        }
        return amount;
    }
};