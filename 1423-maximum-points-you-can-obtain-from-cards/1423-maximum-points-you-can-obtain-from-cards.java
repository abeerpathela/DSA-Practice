class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n=cardPoints.length;
        int currentSum=0;
        for(int i=0; i<k; i++){
            currentSum=currentSum+cardPoints[i];
        }
        int maxSum=currentSum;
        int rightIndex=n-1;
        for(int i=k-1; i>=0; i--){
            currentSum=currentSum-cardPoints[i];
            currentSum=currentSum+cardPoints[rightIndex];
            rightIndex--;
            maxSum=Math.max(maxSum,currentSum);
        }
        return maxSum;
    }
}