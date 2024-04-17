import java.util.*;

// Tested
class Pair implements Comparable<Pair> {
    int sum;
    int index;
    public Pair(int sum, int index) {
        this.sum = sum;
        this.index = index;
    }

    public int compareTo(Pair a) {
        if (a.sum == this.sum)
            return a.index - this.index;
        return a.sum - this.sum;
    }
}

class Solution {
    final int max = 6;
    public int solution(int[] A) {
        PriorityQueue<Pair> pairHeap = new PriorityQueue<>();
        int n = A.length;
        int[] prevPeb = new int[n];
        int[] maxSum = new int[n];
        prevPeb[0] = 0;
        maxSum[0] = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i - 1] >= 0) {
                prevPeb[i] = i-1;
                maxSum[i] = maxSum[i - 1] + A[i];
            }
            else {
                if (i - prevPeb[i - 1] > max) {
                    while (true) {
                        Pair p = pairHeap.poll();
                        if (i - p.index <= max) {
                            prevPeb[i] = p.index;
                            maxSum[i] = p.sum + A[i];
                            break;
                        }
                    }
                }
                else {
                    prevPeb[i] = prevPeb[i - 1];
                    maxSum[i] = A[i] + maxSum[prevPeb[i - 1]];
                }
                pairHeap.add(new Pair(maxSum[i], i));
            }
        }
        return maxSum[n - 1];
    }
}

