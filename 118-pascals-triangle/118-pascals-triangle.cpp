class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        /*
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
        */
        /*
        TC: 0(n!)
        MC: 0(n!) + 0(n) = n!
        */
        vector<vector<int>> triangle {{1}};
        vector<int>lastRow = {1};
        vector<int>newRow;
        
        for(int row=1;row<numRows;row++)//n*2 3 4//n=5
        {
            newRow.push_back(1);
            for(int i=1;i<lastRow.size();i++)//
            {
                newRow.push_back(lastRow[i]+lastRow[i-1]);
            }
            newRow.push_back(1);
            triangle.push_back(newRow);
            lastRow = newRow; //0(n)
            newRow.clear();
        }
        
        return triangle;        
    }
};