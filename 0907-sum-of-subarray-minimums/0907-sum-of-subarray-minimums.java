class Solution {
    public int sumSubarrayMins(int[] arr) {
        Stack<Integer> st= new Stack<>();
        long res=0;
        int n=arr.length;
        int mod=1_000_000_007;

        for(int i=0; i<=n; i++){

            int current= (i==n)? 0 : arr[i];

            while(!st.isEmpty() && arr[st.peek()] > current){
                int mid=st.pop();
                int leftIndex=st.isEmpty() ? -1 : st.peek();
                int rightIndex=i;

                int left= mid-leftIndex;
                int right=rightIndex-mid;

                res = res + ((long) arr[mid] * left * right);
                res=res%mod;
            }

            st.push(i);
        }

        return (int) res;
    }
}