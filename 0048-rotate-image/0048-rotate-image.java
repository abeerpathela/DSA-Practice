class Solution {
    public void rotate(int[][] matrix) {
        int row_size=matrix[0].length;
        int col_size=matrix.length;

        int[][] tempArray=new int[col_size][row_size];

        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                tempArray[j][row_size-1-i]=matrix[i][j];
            }
        }

        for(int cpy1=0; cpy1<col_size; cpy1++ ){
            for(int cpy2=0; cpy2<row_size; cpy2++){
                matrix[cpy1][cpy2]=tempArray[cpy1][cpy2];
            }
        }
        
    }
}