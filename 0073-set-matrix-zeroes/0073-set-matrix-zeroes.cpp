class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<bool>ZeroRow(rows,false);
        vector<bool>ZeroCol(cols,false);

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j]==0){
                    ZeroRow[i]=true;
                    ZeroCol[j]=true;
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(ZeroRow[i]==true || ZeroCol[j]==true){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};