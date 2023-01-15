import java.util.Arrays;
import java.util.Scanner;

public class PrimsMSTJava {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] graph = new int[n][n];
        for (int i = 0; i < m; i++) {
            System.out.println("Input edge " + (i + 1) + " with cost:");
            int from = in.nextInt();
            int to = in.nextInt();
            int cost = in.nextInt();
            graph[from][to] = cost;
            graph[to][from] = cost;
        }
        int[] minEdge = new int[n];
        Arrays.fill(minEdge, Integer.MAX_VALUE);
        boolean[] used = new boolean[n];
        System.out.println("Input start vertex:");
        int start = in.nextInt();
        minEdge[start] = 0;
        long result = 0;
        for (int i = 0; i < n; i++) {
            int min = Integer.MAX_VALUE;
            int minVertex = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j] && min > minEdge[j]) {
                    min = minEdge[j];
                    minVertex = j;
                }
            }
            if (minVertex == -1) {
                System.out.println("No MST");
                return;
            }
            used[minVertex] = true;
            result += min;
            for (int j = 0; j < n; j++) {
                if (graph[minVertex][j] != 0 && !used[j]) {
                    minEdge[j] = Math.min(minEdge[j], graph[minVertex][j]);
                }
            }
        }
        System.out.println(result);
    }
}