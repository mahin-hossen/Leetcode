class Solution {
public:
    
    vector<int> makeTriangle(vector<vector<int>>& triangle,vector<int>& lastRow)
    {
        vector<int> newRow{1};
        for(int i=1;i<lastRow.size();i++)
        {
            newRow.push_back(lastRow[i-1]+lastRow[i]);
        }
        newRow.push_back(1);
        
        triangle.push_back(newRow);        
        return newRow;
    }
    
    vector<vector<int>> generate(int numRows) 
    {
        /*
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
        */        
        vector<vector<int>>triangle{{1}};
        vector<int>lastRow{1};
        
        for(int row=1;row<numRows;row++)
        {
            lastRow = makeTriangle(triangle,lastRow);
        }
        
        return triangle;       
    }
};