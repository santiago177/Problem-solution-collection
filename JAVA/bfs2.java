import java.util.*;

class Solution {
    private boolean intersects(int[] A, int[] B, int i, int j) {
        int mini = Math.min(A[i], B[i]);
        int maxi = Math.max(A[i], B[i]);
        int minj = Math.min(A[j], B[j]);
        int maxj = Math.max(A[j], B[j]);
        if (mini < minj) {
            return maxi >= minj;
        }
        return mini <= maxj;
    }

    public int solution(int[] A, int[] B) {
        int max = 0;
        LinkedList<HashSet<Integer>> nodes = new LinkedList<>();
        boolean[] visited = new boolean[A.length];
        boolean[] intersect = new boolean[A.length];
        HashSet<Integer> init = new HashSet<>();
        init.add(0);
        nodes.add(init);
        visited[0] = true;
        max = 1;
        while (!nodes.isEmpty()) {
            HashSet<Integer> node = nodes.poll();
            for (int i = 0; i < A.length; i++) {
                if (!visited[i]) {
                    System.out.println("I = " + i);
                    boolean bad = false;
                    System.out.println("Numbers");
                    for (int j : node) {
                        System.out.printf("Intersects i %d j %d\n", i, j);
                        if (intersects(A, B, i, j)) {
                            bad = true;
                            break;
                        }
                    }
                    if (bad)
                        continue;
                    
                    System.out.println("Adding "+ i);
                    newNode.add(i);
                    nodes.add(newNode);
                    visited[i] = true;
                    max = Math.max(max, newNode.size());
                }
            }
            if (nodes.isEmpty()) {
                for (int i = 0; i < A.length; i++) {
                    if (!visited[i]) {
                        HashSet<Integer> newNode = new HashSet<>(node);
                        newNode.add(i);
                        nodes.add(newNode);
                        visited[i] = true;
                        break;
                    }
                }
            }
        }
        return max;
    }
}