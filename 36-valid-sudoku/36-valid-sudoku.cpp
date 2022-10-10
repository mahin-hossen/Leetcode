class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> seen;
        for(int i=0;i<board[i].size();i++)
        {
            for(int j=0;j<board[j].size();j++)
            {
                if(board[i][j]!='.')
                {
                    string r = to_string(board[i][j])+"row "+to_string(i);
                    string c = to_string(board[i][j])+"col "+to_string(j);
                    string box = to_string(board[i][j])+"box "+to_string(i/3)+to_string(j/3);

                    if(seen.count(r) || seen.count(c) || seen.count(box))
                    {
                        return false;                        
                    }
                    seen.insert(r);
                    seen.insert(c);
                    seen.insert(box); 
                }                                 
            }
        }
        
        return true;
    }
};