// Middle of Stack 

import java.util.Stack;
class Middle_Of_Stack {
    // without recurrsion 
    
    // public static int middleOfStack(Stack<Integer> s){
    //     int size;
    //     size=s.size();
    //     if(size==0){
    //         return -1;
    //     }
    //     int midDepth=size/2;
    //     for(int i=1; i<=midDepth; i++){
    //         s.pop();
    //     }
    //     return s.peek();
    // }
    
    // with recurrsion
    public static int middleOfStackHelp(Stack<Integer> s,int currentDepth,int size,int answer){
        if(currentDepth == size/2){
           return s.peek();
        }
        
        int topVal=s.peek();
        s.pop();
        
        answer=middleOfStackHelp(s,currentDepth+1,size,answer);
        
        s.push(topVal);
        
        return answer;
    }
    public static int middleOfStack(Stack<Integer> s){
        int size;
        size=s.size();
        if(size==0){
            return -1;
        }
        
        int currentDepth=0;
        int answer=0;
        
        answer=middleOfStackHelp(s,currentDepth,size,answer);
        return answer;
    }
    public static void main(String[] args) {
        Stack<Integer> s=new Stack<>();
        
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        
        System.out.println(middleOfStack(s));
        
    }
}