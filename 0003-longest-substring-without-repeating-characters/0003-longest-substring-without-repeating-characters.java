class Solution {
     int maxLen=0;
    public void generate(String s,int currentIndex){
        if(currentIndex>=s.length()){
            return;
        }
        HashSet<Character>set=new HashSet<>();
        for(int i=currentIndex; i<s.length(); i++){
            char ch=s.charAt(i);
            if(set.contains(ch)){
                break;
            }
            set.add(ch);
            maxLen=Math.max(maxLen,set.size());
        }
        generate(s,currentIndex+1);
    }
    public int lengthOfLongestSubstring(String s) {
        maxLen=0;
        generate(s,0);
        return maxLen;
    }
}