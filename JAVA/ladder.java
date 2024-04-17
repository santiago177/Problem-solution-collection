import java.util.*;

class Solution {
    public int[] solution(int[] A, int[] B) {
        int size = A.length;        
        int[] answers = new int[size];
        for (int z = 0; z < size; z++) {
            int mod = 1 << B[z];
            int max = A[z];
            int[] counts = new int[max + 1];
            counts[1] = 1;
            counts[2] = 2;            
            boolean[] visited = new boolean[max + 1];
            visited[1] = true;
            visited[2] = true;
            System.out.println("herte");
            LinkedList<Integer> positions = new LinkedList<>();
            positions.add(1);
            positions.add(2);
            while (positions.size() != 0) {
                int current = positions.poll();
                for (int i = 1; i <= 2; i++) {
                    if (current + i > max)
                        break;
                    counts[current + i] = (counts[current] + counts[current + i]) % mod;
                    if (current + i <= max && !visited[current + i]) {
                        visited[current + i] = true;
                        positions.add(current + i);
                    }
                }
            }
            answers[z] = counts[max];
        }
        return answers;
    }
}
