class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat[0].size();
        int n = mat.size();
        if(m*n!=r*c) return mat;

        vector<vector<int>> reshapedMatrix(r,vector<int>(c));
        vector<int> mat2;
        int col = 0, row = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
			  reshapedMatrix[row][col] = mat[i][j];
			  col++;
			  if(col==c) col=0,row++;
            }
        }

        
        return reshapedMatrix;
    }

};