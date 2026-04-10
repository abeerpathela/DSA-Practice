import java.util.*;

class Solution {
    public int minimumDistance(int[] nums) {
        Map<Integer, List<Integer>> map = new HashMap<>();

        // store indices
        for (int i = 0; i < nums.length; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        int ans = Integer.MAX_VALUE;

        // process each value
        for (List<Integer> list : map.values()) {
            if (list.size() < 3) continue;

            // check consecutive triplets
            for (int i = 0; i + 2 < list.size(); i++) {
                int left = list.get(i);
                int right = list.get(i + 2);

                ans = Math.min(ans, 2 * (right - left));
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}