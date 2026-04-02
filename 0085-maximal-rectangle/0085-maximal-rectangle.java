class Solution {
    private int largestRectangleArea(int[] heights){
        Stack<Integer> st=new Stack<>();
        int maxArea=0;
        int n=heights.length;
        for(int i=0; i<=n; i++){
            int currentHeight=(i==n)?0:heights[i];

            while(!st.isEmpty() && currentHeight<heights[st.peek()]){
                int height=heights[st.pop()];
                int width;
                if(st.isEmpty()){
                    width=i;
                }
                else{
                    width=i-st.peek()-1;
                }
                maxArea=Math.max(maxArea,height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0){
            return 0;
        }
        int n=matrix.length;
        int m=matrix[0].length;
        int[] heights=new int[m];
        int maxArea=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    heights[j]=heights[j]+1;
                }
                else{
                    heights[j]=0;
                }
            }
            maxArea=Math.max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
}