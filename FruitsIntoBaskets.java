// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.HashMap;
class FruitsIntoBaskets {
    public static int fruitIntoBaskets(int[] fruits){
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<fruits.length; i++){
            map.put(fruits[i],map.getOrDefault(fruits[i],0)+1);
        }
        int sum=0;
        for(int key: map.keySet()){
            sum=sum+map.get(key);
        }
        return sum;
    }
    public static void main(String[] args) {
        int[] fruits={1,2,1};
        System.out.println(fruitIntoBaskets(fruits));
    }
}