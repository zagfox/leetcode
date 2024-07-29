---
date:   2024-06-16
---

# Leetcode 733: Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

## Depth First Search
The DFS approach checks one point at a time, after completion, try to check all its neighbors recursively. A visited helper structure is often needed to avoid duplicate checks.
Time complexity: O(N)

## DFS Java Code
<pre>
<code>
class Solution {
    public void dfs(int[][] image, int sr, int sc, int originColor, int color, boolean[][] visited) {
        int M = image.length;
        int N = image[0].length;

        if (visited[sr][sc]) return;
        visited[sr][sc] = true;

        if (image[sr][sc] != originColor) {
            return;
        }
        image[sr][sc] = color;
        int[][] directions = new int[][]{
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        for (int[] direction : directions) {
            int nr = sr + direction[0];
            int nc = sc + direction[1];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }
            dfs(image, nr, nc, originColor, color, visited);
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int M = image.length;
        int N = image[0].length;
        boolean[][] visited = new boolean[M][N];
        dfs(image, sr, sc, image[sr][sc], color, visited);
        return image;
    }
}
</code>
</pre>

## Breath First Search
The BFS approach tries to expand on all graph's border at a time. All the graph's border is stored
in a queue, and in each round, all graph points in the queue is examined and potentially flooded.

Note that the algorithm should check if the next visited data point color is the same as the starting point original color.

## BFS Java Code
<pre>
<code>
class Solution {
    class Point {
        public int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int M = image.length;
        int N = image[0].length;
        int originColor = image[sr][sc];
        boolean[][] visited = new boolean[M][N];
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(sr, sc));
        while (!queue.isEmpty()) {
            Queue<Point> newQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                Point p = queue.remove();
                if (visited[p.x][p.y]) {
                    continue;
                }
                visited[p.x][p.y] = true;
                image[p.x][p.y] = color;

                int[][] directions = new int[][]{
                    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
                };
                for (int[] direction : directions) {
                    int nx = p.x + direction[0];
                    int ny = p.y + direction[1];
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                        continue;
                    }
                    if (visited[nx][ny]) {
                        continue;
                    }
                    if (image[nx][ny] != originColor) {
                        continue;
                    }
                    newQueue.add(new Point(nx, ny));
                }
            }
            queue = newQueue;
        }
        return image;
    }
}
</code>
</pre>