import java.util.*;

class Solution {

    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {

        int n = online.length;

        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();

        int high = 0;

        for (int[] e : edges) {
            graph[e[0]].add(new int[]{e[1], e[2]});
            high = Math.max(high, e[2]);
        }

        int low = 0;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, graph, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    private boolean check(int limit,
                          List<int[]>[] graph,
                          boolean[] online,
                          long k) {

        int n = graph.length;

        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);

        PriorityQueue<long[]> pq =
                new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1]));

        dist[0] = 0;
        pq.offer(new long[]{0, 0});

        while (!pq.isEmpty()) {

            long[] cur = pq.poll();

            int node = (int) cur[0];
            long cost = cur[1];

            if (cost > dist[node])
                continue;

            if (node == n - 1)
                return true;

            for (int[] next : graph[node]) {

                int v = next[0];
                int w = next[1];

                if (w < limit)
                    continue;

                if (v != n - 1 && !online[v])
                    continue;

                long newCost = cost + w;

                if (newCost < dist[v] && newCost <= k) {
                    dist[v] = newCost;
                    pq.offer(new long[]{v, newCost});
                }
            }
        }

        return false;
    }
}