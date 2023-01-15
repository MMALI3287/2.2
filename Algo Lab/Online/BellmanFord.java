import java.util.Scanner;

public class BellmanFord {
  public static class Edge {
    int u, v, weight;

    public Edge(int u, int v, int weight) {
      this.v = v;
      this.u = u;
      this.weight = weight;
    }
  }

  public static boolean bellmanFord(Edge[] edges, int[] dist, int[] parent, int V, int source) {

    java.util.Arrays.fill(dist, Integer.MAX_VALUE);
    java.util.Arrays.fill(parent, -1);
    dist[source] = 0;
    parent[source] = source;

    for (int v = 0; v < V - 1; v++) {
      for (Edge edge : edges) {
        if (dist[edge.u] + edge.weight < dist[edge.v]) {
          dist[edge.v] = dist[edge.u] + edge.weight;
          parent[edge.v] = edge.u;
        }
      }
    }
    for (Edge edge : edges) {
      if (dist[edge.u] + edge.weight < dist[edge.v]) {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {

    int E, V, source;
    Scanner sc = new Scanner(System.in);
    int u, v, weight;
    System.out.print("Enter the number of vertices: ");
    V = sc.nextInt();
    System.out.print("Enter the number of edges: ");
    E = sc.nextInt();

    Edge[] edges = new Edge[E];
    int[] parent = new int[V];
    int[] dist = new int[V];

    for (int i = 0; i < E; i++) {
      System.out.println("Enter the number " + (i + 1) + " edge and weight");
      System.out.print("u--> ");
      u = sc.nextInt();
      System.out.print("v--> ");
      v = sc.nextInt();
      System.out.print("Weight--> ");
      weight = sc.nextInt();
      edges[i] = new Edge(u, v, weight);
    }

    System.out.println("Enter the source");
    source = sc.nextInt();

    if (bellmanFord(edges, dist, parent, V, source)) {
      for (int i = 0; i < V; i++) {
        System.out.print("From Source " + source + " to node " + i + " : ");
        if (dist[i] == Integer.MAX_VALUE) {
          System.out.println("No path found");
        } else {
          System.out.println("Shortest Distance Weight: " + dist[i]);
          System.out.print("Path: ");
          int j = i;
          while (j != source) {
            System.out.print(j + "<-");
            j = parent[j];
          }
          System.out.println(source);
        }
      }
    } else {
      System.out.println("Negative cycle detected");
    }
  }
}
