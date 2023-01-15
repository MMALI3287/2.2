import static java.lang.Double.POSITIVE_INFINITY;

import java.util.Vector;

public class FloydWarshall {

    private int n;
    private double[][] d;
    private Integer[][] pi;

    public FloydWarshall(double[][] matrix) {
        n = matrix.length;
        d = new double[n][n];
        pi = new Integer[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != POSITIVE_INFINITY)
                    pi[i][j] = j;
                d[i][j] = matrix[i][j];
            }
        }
    }

    public double[][] getApspMatrix() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        pi[i][j] = pi[i][k];
                    }
                }
            }
        }
        return d;
    }

    public Vector<Integer> reconstructShortestPath(int start, int end) {
        Vector<Integer> path = new Vector<Integer>();
        if (d[start][end] == POSITIVE_INFINITY)
            return path;
        int at = start;
        for (; at != end; at = pi[at][end]) {
            path.add(at);
        }
        path.add(end);
        return path;
    }

    public static double[][] createGraph(int n) {
        double[][] matrix = new double[n][n];
        for (int i = 0; i < n; i++) {
            java.util.Arrays.fill(matrix[i], POSITIVE_INFINITY);
            matrix[i][i] = 0;
        }
        return matrix;
    }

    public static void main(String[] args) {

        int n = 5;
        double[][] m = createGraph(n);

        m[0][1] = 1;
        m[0][2] = 1;
        m[1][2] = 3;
        m[1][4] = 5;
        m[2][1] = 2;
        m[2][4] = 4;
        m[3][2] = 1;
        m[4][3] = 2;

        FloydWarshall solver = new FloydWarshall(m);
        double[][] dist = solver.getApspMatrix();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                System.out.printf("Shortest path: %d to %d is %.3f\n", i, j, dist[i][j]);

        System.out.println();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Vector<Integer> path = solver.reconstructShortestPath(i, j);
                String str = "";
                if (path.size() == 0) {
                    str = String.format("Path Does Not Exist");
                } else {
                    str = String.format("%d", path.get(0));
                    for (int k : path)
                        str += String.format(" -> %d", k);
                }

                System.out.printf("Shortest path %d to %d is:[ %s ]\n", i, j, str);
            }
        }
    }
}