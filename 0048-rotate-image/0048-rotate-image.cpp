class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row_size=matrix.size();
        int col_size=matrix[0].size();

        vector<vector<int>>answer(col_size,vector<int>(row_size));

        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                answer[j][row_size-1-i]=matrix[i][j];
            }
        }

        matrix=answer;
    }
};