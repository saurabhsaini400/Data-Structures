import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
class Solution {
    public int longestConsecutive(int[] nums) {
        SortedSet<Integer> sortedSet = new TreeSet<>();
        if(nums.length ==0){
            return 0;
        }
        int count=0,p=0;

        // Add elements from the array to the set
        for (int element : nums) {
            sortedSet.add(element);
        }
        System.out.println("Set: " + sortedSet);
        // Get an iterator for the sorted set
        Iterator<Integer> iterator = sortedSet.iterator();

        // Find the difference between adjacent elements using the iterator
        Integer prevElement = null;
        while (iterator.hasNext()) {
            Integer currentElement = iterator.next();
            if (prevElement != null) {
                int difference = currentElement - prevElement;
                if(difference == 1){
                    count++;
                }
                else{
                    p=Math.max(p,count);
                    count=0;
                }
            }
            prevElement = currentElement;
        }
        p=Math.max(p,count);
        return p+1;
    }
}