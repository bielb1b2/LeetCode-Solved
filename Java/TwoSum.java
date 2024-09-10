import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public static void main(String args[]) {

    }   

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hasher = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if(hasher.containsKey(nums[i])) {
                return new int[] {hasher.get(nums[i]), i};
            }

        hasher.put(target-nums[i], i);
        }

        throw new IllegalArgumentException("Nenhuma solução encontrada");
    }
}
