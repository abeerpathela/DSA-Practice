class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st= new Stack<>();

        for(int i=0; i<asteroids.length; i++){

            boolean destroyed=false;

            while(!st.isEmpty() && st.peek()>0 && asteroids[i]<0){

                if(Math.abs(st.peek())<Math.abs(asteroids[i])){
                    st.pop();
                }
                else if(Math.abs(st.peek()) == Math.abs(asteroids[i])){
                    st.pop();
                    destroyed=true;
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }

            }

            if(!destroyed){
                st.push(asteroids[i]);
            }

        }

        int[] results=new int[st.size()];
        for(int i=st.size()-1; i>=0; i--){
            results[i]=st.pop();
        }
        return results;
    }
}