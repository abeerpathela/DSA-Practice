class MinStack {
    Stack<Integer> s;
    Stack<Integer> minSt=new Stack<>();
    public MinStack() {
        s=new Stack<>();
    }
    
    public void push(int val) {
        s.push(val);
        if((minSt.isEmpty())||(val <= minSt.peek())){
            minSt.push(val);
        }
    }
    
    public void pop() {
        if(!s.isEmpty()){
            if(s.peek().equals(minSt.peek())){
                minSt.pop();
            }
            s.pop();
        }
    }
    
    public int top() {
        if(!s.isEmpty()){
            return s.peek();
        }
        return -1;
    }
    
    public int getMin() {
        return minSt.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */