class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> bucket;
        /*
        ()[]{}
        */
        for(auto c : s)
        {
            if(bucket.empty()) bucket.push(c);
            else if(bucket.top()=='(' && c==')') bucket.pop();
            else if(bucket.top()=='[' && c==']') bucket.pop();
            else if(bucket.top()=='{' && c=='}') bucket.pop();
            else bucket.push(c);
        }
        
        return bucket.empty();
    }
};