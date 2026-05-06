class Solution {
    public int numberOfSubstrings(String s) {
        int[] freq=new int[3];
        int left=0;
        int count=0;
        for(int right=0; right<s.length(); right++){
            freq[s.charAt(right)-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                count=count+(s.length()-right);  // s.length()-right will tell the number of substrings possible till now with that combo 
                freq[s.charAt(left)-'a']--;
                left++;
            }
        }
        return count;
    }
}