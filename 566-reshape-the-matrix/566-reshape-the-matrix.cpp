class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat[0].size();
        int n = mat.size();
        if(m*n!=r*c) return mat;

        vector<vector<int>> reshapedMatrix;
        vector<int> mat2;
        int col = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat2.push_back(mat[i][j]);
                col++;
                if(col==c)
                {
                    reshapedMatrix.push_back(mat2);
                    mat2.clear();
                    col=0;
                 }
            }
        }
        
        return reshapedMatrix;
    }

};