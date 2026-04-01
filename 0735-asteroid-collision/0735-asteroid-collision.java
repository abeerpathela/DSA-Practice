class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st= new Stack<>(); // this will store the asteroids which are still active and didnt get destroyed 

        for(int i=0; i<asteroids.length; i++){

            boolean destroyed=false;

            while(!st.isEmpty() && st.peek()>0 && asteroids[i]<0){  // this loop will make the asteroids collide 
// one asteroid can destroy many asteroids so thats why we used while loop 
                if(Math.abs(st.peek())<Math.abs(asteroids[i])){ // this will destroy the stack  asteroid  only 
                    st.pop();
                }
                else if(Math.abs(st.peek()) == Math.abs(asteroids[i])){   // in this case both the asteroid got destroyed 
                    st.pop();
                    destroyed=true;
                    break;
                }
                else{ // this case when the current asteroid got broken but not the stack one asteroid 
                    destroyed=true;
                    break;
                }

            }

            if(!destroyed){  // this will push only the asteroids which did not get destroyed 
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