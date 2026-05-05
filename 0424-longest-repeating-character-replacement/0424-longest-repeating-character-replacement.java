class Solution {
    public int longestChar(String s,int k,char ch){
        int left=0;
        int charCount=0;
        int maxLen=0;
        for(int right=0; right<s.length(); right++){
            if(s.charAt(right)==ch){
                charCount++;
            }
            while((right - left + 1) - charCount > k){
                if(s.charAt(left)==ch){
                    charCount--;
                }
                left++;
            }
            maxLen=Math.max(right-left+1,maxLen);
        }
        return maxLen;
    }
    public int characterReplacement(String s, int k) {
        int answer=0;

        for(char ch='A'; ch<='Z'; ch++){
            answer=Math.max(answer,longestChar(s,k,ch));
        }
        
        return answer;
    }
}