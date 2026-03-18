public class stackWithoutHeaderFile {
    static class Node{
        int data;
        Node(int data){
            this.data=data;
        }
    }
    static class Stack{
        Node[] arr; // array of refereneces (pointer array)
        int top;
        int capacity;
        
        Stack(int size){
            arr=new Node[size];
            capacity=size;
            top=-1;
        }
        
        void push(int val){
            if(top == capacity-1){
                System.out.println("Stack Overflow");
                return;
            }
            top++;
            arr[top]=new Node(val);
        }
        
        int pop(){
            if(top == -1){
                System.out.println("Nothing to pop");
                return -1;
            }
            int val=arr[top].data;
            arr[top]=null;
            top--;
            return val;
        }
        
        int peek(){
            if(top == -1){
                return -1;
            }
            return arr[top].data;
        }
        
        int size(){
            return top+1;
        }
        
    }
    public static void main(String[] args) {
         Stack s = new Stack(5);

        s.push(10);
        s.push(20);
        s.push(30);

        System.out.println(s.pop());  // 30
        System.out.println(s.peek()); // 20
        System.out.println(s.size()); // 2
    }
}
